#include<stdio.h>
int fib[41][2];
int main() {
	int N, T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		fib[0][0] = 1; fib[0][1] = 0;
		fib[1][0] = 0; fib[1][1] = 1;
		for (int i = 2; i <= N; i++) {
			fib[i][0] = fib[i - 1][0] + fib[i - 2][0];
			fib[i][1] = fib[i - 1][1] + fib[i - 2][1];
		}
		printf("%d %d\n", fib[N][0], fib[N][1]);
	}
	return 0;
}