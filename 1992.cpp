#include<stdio.h>
int arr[65][65];
bool isQuad(int x, int y, int n) {
	int tmp = arr[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (tmp != arr[i][j])
				return false;
		}
	}
	return true;
}

void divde(int x, int y, int n) {
	if (isQuad(x, y, n))
		printf("%d", arr[x][y]);
	else {
		printf("(");
		divde(x, y, n / 2);
		divde(x, y + n / 2, n / 2);
		divde(x + n / 2, y, n / 2);
		divde(x + n / 2, y + n / 2, n / 2);
		printf(")");
	}
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	divde(0, 0, N);
	return 0;
}