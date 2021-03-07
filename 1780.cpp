#include<stdio.h>
int arr[3000][3000];
int ans[3];
int isPaper(int x, int y, int n) {
	int tmp = arr[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (tmp != arr[i][j])
				return 0;
		}
	}
	return 1;
}

void cutPaper(int x, int y, int n) {
	if (isPaper(x, y, n))ans[arr[x][y] + 1]++;
	else {
		for (int i = x; i < x + n; i += n / 3) {
			for (int j = y; j < y + n; j += n / 3) {
				cutPaper(i, j, n / 3);
			}
		}
	}
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	cutPaper(0, 0, N);
	for (int i = 0; i < 3; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}