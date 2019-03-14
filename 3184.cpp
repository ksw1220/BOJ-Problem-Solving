#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
struct pos {
	int x, y;
};
queue<pos> que;
vector<pos> group;
char map[251][251];
bool visit[251][251];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int main() {
	int R, C;
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)for (int j = 0; j < C; j++)scanf("%c", &map[i][j]);
	for (int i = 0; i < R; i++)for (int j = 0; j < C; j++) {
		if (visit[i][j]||map[i][j]=='#')continue;
		int sheep = 0, wolf = 0;
		que.push({ i,j });
		visit[i][j] = true;
		while (!que.empty()) {
			pos now = que.front();
			que.pop();
			for (int d = 0; d < 4; d++) {
				int tox = now.x + dx[d];
				int toy = now.y + dy[d];
				if (tox < 0 || toy < 0 || tox >= R|| toy >= C || visit[tox][toy] || map[tox][toy] == '#')continue;
				if (map[tox][toy] == 'o')sheep++;
				else if (map[tox][toy] == 'v')wolf++;
				visit[tox][toy] = true;
				que.push({ tox,toy });
			}
		}
		group.push_back({ sheep,wolf });
	}
	int sheep = 0, wolf = 0;
	for (int i = 0; i < group.size(); i++) {
		if (group[i].x > group[i].y)sheep += group[i].x;
		else wolf += group[i].y;
	}
	printf("%d %d", sheep, wolf);
	return 0;
}
