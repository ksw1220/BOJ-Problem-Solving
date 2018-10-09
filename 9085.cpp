#include<stdio.h>
int main() {
	int T, N, tmp, ans;
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &tmp);
			ans += tmp;
		}
		printf("%d\n", ans);
	}
	return 0;
}