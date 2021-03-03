#include<stdio.h>
int map[501][501];
int M, N, B;
int calculate(int h,int b) {
	int low = 0, high = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] > h) high += map[i][j] - h;
			else low += h - map[i][j];
		}
	}
	b += high;
	if (b < low)return 987654321;
	return low + high * 2;
}
int main() {
	scanf("%d %d %d", &M, &N, &B);
	int min = 300;
	int max = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (min > map[i][j])min = map[i][j];
			if (max < map[i][j])max = map[i][j];
		}
	}
	int ans = min;
	int time = calculate(min, B);
	int tmp = min;
	//printf("%d %d\n", time, ans);
	while (tmp<=max) {
		int t = calculate(++tmp, B);
		//printf("%d %d\n", t, tmp);
		if (t < time) {
			time = t;
			ans = tmp;
		}
	}
	printf("%d %d\n", time, ans);
	return 0;
}