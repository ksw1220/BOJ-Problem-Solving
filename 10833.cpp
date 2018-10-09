#include<stdio.h>
int main() {
	int ans = 0, a, b, N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		ans += b%a;
	}
	printf("%d", ans);
	return 0;
}