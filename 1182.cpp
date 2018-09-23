#include<stdio.h>
#include<iostream>
using namespace std;
int num[21];
int ans = 0, N, S;
void dfs(int idx, int now) {
	if (idx == N) {
		if (now + num[idx] == S)ans++;
		if (now == S)ans++;
		return;
	}
	dfs(idx + 1, now + num[idx]);
	dfs(idx + 1, now);
}
int main() {
	scanf("%d %d", &N, &S);
	for (int i = 1; i <= N; i++)scanf("%d", &num[i]);
	dfs(1, 0);
	if (S == 0)ans--;
	printf("%d", ans);
	return 0;
}