#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	long long N, M;
	scanf("%lld %lld", &N, &M);
	long long A = 0, B = 0;
	for (long long i = 2; i <= N; i *= 2) A += N / i;
	for (long long i = 2; i <= M; i *= 2) A -= M / i;
	for (long long i = 2; i <= N - M; i *= 2) A -= (N - M) / i;
	for (long long i = 5; i <= N; i *= 5) B += N / i;
	for (long long i = 5; i <= M; i *= 5) B -= M / i;
	for (long long i = 5; i <= N - M; i *= 5) B -= (N-M)/ i;
	printf("%lld", min(A, B));
	return 0;
}