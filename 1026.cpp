#include<stdio.h>
#include<algorithm>
using namespace std;
int A[51], B[51];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &A[i]);
	for (int i = 0; i < N; i++)scanf("%d", &B[i]);
	sort(A, A + N);
	sort(B, B + N);
	reverse(B, B + N);
	int ans = 0;
	for (int i = 0; i < N; i++)ans += A[i] * B[i];
	printf("%d", ans);
	return 0;
}