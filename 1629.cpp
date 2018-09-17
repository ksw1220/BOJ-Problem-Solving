#include<stdio.h>
long long A, B, C;
long long func(long long X, long long N) {
	long long re;
	if (N == 0)return 1;
	if (N % 2 == 1) {
		return (X*func(X, N - 1)) % C;
	}
	else {
		re = func(X, N / 2);
		return (re*re) % C;
	}
}
int main() {
	scanf("%lld %lld %lld", &A, &B, &C);
	long long ans = func(A, B);
	printf("%lld", ans);
	return 0;
}