#include<stdio.h>
int main() {
	int ans = 0, N;
	scanf("%d", &N);
	N = 1000 - N;
	while (N >= 500) {
		N -= 500;
		ans++;
	}
	while (N >= 100) {
		N -= 100;
		ans++;
	}
	while (N >= 50) {
		N -= 50;
		ans++;
	}
	while (N >= 10) {
		N -= 10;
		ans++;
	}
	while (N >= 5) {
		N -= 5;
		ans++;
	}
	ans += N;
	printf("%d", ans);
	return 0;
}