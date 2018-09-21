#include<stdio.h>
int main() {
	long long N;
	scanf("%lld", &N);
	long long ans = (N - 1)*N*(N + 1) / 2;
	printf("%lld", ans);
	return 0;
}