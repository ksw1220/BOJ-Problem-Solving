#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int N, M, K, ans = 0;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i <= K; i++) {
		if (i > M)break;
		int A = N - (K - i);
		int B = M - i;
		ans = max(ans, min(A / 2, B));
	}
	printf("%d", ans);
	return 0;
}