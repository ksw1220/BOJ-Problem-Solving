#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define START_X		2
#define START_Y		3
#define FINAL_X		48
#define FINAL_Y		22

#define ENEMY_MAX	32

int GAME_LEVEL = 8;
int life = 5;
int aircraft_x;
int aircraft_y;
int posx = 100;
int posy = 100;
int enemy_x[ENEMY_MAX];
int enemy_y[ENEMY_MAX];

int enemy_status[ENEMY_MAX] = { 0 };

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
// 주변 배경을 그리는 함수
void draw_background()
{
	int i;
	printf("--------------------------------------------------\n");
	printf("|                STAR TREK 1.0                   |\n");
	printf("--------------------------------------------------\n");

	for (i = 0; i < (FINAL_Y - START_Y + 1); i++) {
		printf("|　　　　　　　　　　　　　　　　　　　　　　　　|\n");
	}
	printf("--------------------------------------------------\n");
}
// 우주선의 위치를 키보드 입력에 따라 업데이트 하여 그리는 함수
void update_aircraft(int move_x, int move_y)
{
	gotoxy(aircraft_x, aircraft_y);
	printf("   ");
	gotoxy(aircraft_x, aircraft_y + 1);
	printf("   ");

	aircraft_x += move_x;
	aircraft_y += move_y;

	gotoxy(aircraft_x, aircraft_y);
	printf(" A ");
	gotoxy(aircraft_x, aircraft_y + 1);
	printf("AOA");
}
// 적들을 그리는 함수
void draw_all_enemies()
{
	int i;

	for (i = 0; i < ENEMY_MAX; i++) {
		if (enemy_status[i] == 0)
			continue;

		if (enemy_y[i] == posy + 1)continue;
		gotoxy(enemy_x[i], enemy_y[i]);
		printf(" ");
		enemy_y[i] += 1;

		if (enemy_y[i] <= FINAL_Y) {
			gotoxy(enemy_x[i], enemy_y[i]);
			printf("X");
		}
		else
			enemy_status[i] = 0;
	}

	if ((rand() % 10) < GAME_LEVEL) {
		for (i = 0; i < ENEMY_MAX; i++) {
			if (enemy_status[i] == 0) {
				enemy_y[i] = START_Y;
				enemy_x[i] = (rand() % (FINAL_X - START_X)) + START_X;
				enemy_status[i] = 1;
				break;
			}
		}
	}
	gotoxy(51, 3);
	printf("GAME LEVEL : %d", GAME_LEVEL);
	gotoxy(51, 4);
	printf("LIFE : ");
	for (i = 0; i<life; i++)printf("■");
	for (i = life; i<5; i++)printf("□");
}

int check_gameover()
{
	int i;

	for (i = 0; i < ENEMY_MAX; i++) {
		if (enemy_status[i] == 0)
			continue;
		// 적들의 위치가 우주선이 차지하는 좌표인 (x,y+1) (x+1,y+1) (x+2,y+1) (x+1,y)와 만날 때 return 1
		if (((aircraft_x + 1 == enemy_x[i]) && (aircraft_y == enemy_y[i]))
			|| ((aircraft_x == enemy_x[i]) && (aircraft_y + 1 == enemy_y[i]))
			|| ((aircraft_x + 1 == enemy_x[i]) && (aircraft_y + 1 == enemy_y[i]))
			|| ((aircraft_x + 2 == enemy_x[i]) && (aircraft_y + 1 == enemy_y[i]))) {
			enemy_status[i] = 0;
			return 1;

			continue;
		}
	}
	// 만나지 않는다면 return 0
	return 0;
}

int main(int argc, char *argv[]) {
	int i;
	int move_x = 0;
	int move_y = 0;

	aircraft_x = (FINAL_X - START_X) / 2 + START_X;
	aircraft_y = (FINAL_Y - 1);

	srand((unsigned)time(NULL));
	draw_background();
	draw_all_enemies();
	update_aircraft(0, 0);
	for (i = 0; ; i++) {
		if (_kbhit()) {
			char ch = _getch();
			if (ch == 'q' || ch == 'Q') {
				break;
			}
			else if (ch == 0x4D) {
				if ((aircraft_x + 3) < FINAL_X)
					move_x = 1;
			}
			else if (ch == 0x4B) {
				if (aircraft_x > START_X)
					move_x = -1;
			}
			else if (ch == 0x50) {
				if ((aircraft_y + 1) < FINAL_Y)
					move_y = 1;
			}
			else if (ch == 0x48) {
				if (aircraft_y > START_Y)
					move_y = -1;
			}
			else if (ch == '+') GAME_LEVEL++;
			else if (ch == '-') GAME_LEVEL--;

			update_aircraft(move_x, move_y);
			move_x = 0;
			move_y = 0;
		}
		// check_gameover() 함수를 실행하여 현재 우주선이 차지하는 좌표가 적들의 좌표하 일치한다면 life가 1 감소
		if (check_gameover() == 1) {
			life--;
			update_aircraft(move_x, move_y);
			draw_all_enemies();
			if (life <= 0) {
				gotoxy(START_X, FINAL_Y + 2);
				printf("Game Over!");
				_getch();
				return 0;
			}
		}
		// draw_all_enemies() 함수를 실행하기 전에 실행되는 대기 함수
		Sleep(1);
		if ((i % 50) == 0)
			draw_all_enemies();
	}

	gotoxy(START_X, FINAL_Y + 3);
	return 0;
}
