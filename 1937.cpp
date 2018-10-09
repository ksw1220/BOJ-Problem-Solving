#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[501][501], map[501][501];
int N, ans = 0;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
void dfs(int x, int y) {
	int re = 0;
	for (int i = 0; i < 4; i++) {
		int tox = x + dx[i];
		int toy = y + dy[i];
		if (tox < 0 || toy < 0 || tox >= N || toy >= N)continue;
		if (map[x][y] > map[tox][toy]) {
			if (dp[tox][toy] == 0)dfs(tox, toy);
			re = max(re, dp[tox][toy]);
		}
	}
	dp[x][y] = re + 1;
	ans = max(ans, re + 1);
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)scanf("%d", &map[i][j]);
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)if (dp[i][j] == 0)dfs(i, j);
	printf("%d", ans);
	return 0;
}