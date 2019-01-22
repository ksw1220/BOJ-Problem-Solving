#include<stdio.h>
int N, ans[10];
void dfs(int now) {
	if (now == N) {
		int num[10];
		for (int i = 1; i <= N; i++)num[i] = i;
		for (int i = 2; i <= N; i++) {
			if (ans[i] == 0) {
				num[i] = num[i - 1] * 10 + num[i];
				num[i - 1] = 0;
			}
		}
		int sum = num[1], op = 1;
		for (int i = 2; i <= N; i++) {
			if (ans[i] == 1)op = 1;
			else if (ans[i] == 2)op = 2;
			if (op == 1)sum += num[i];
			else sum -= num[i];
		}
		if (sum == 0) {
			printf("1");
			for (int i = 2; i <= N; i++) {
				if (ans[i] == 0)printf(" ");
				else if (ans[i] == 1)printf("+");
				else printf("-");
				printf("%d", i);
			}
			printf("\n");
		}
		return;
	}
	// " "
	ans[now + 1] = 0;
	dfs(now + 1);
	// "+"
	ans[now + 1] = 1;
	dfs(now + 1);
	// "-"
	ans[now + 1] = 2;
	dfs(now + 1);
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		dfs(1);
		printf("\n");
	}
	return 0;
}