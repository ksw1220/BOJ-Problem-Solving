#include<stdio.h>
#include<algorithm>
using namespace std;
int card[2001][2], dp[2001][2001];
bool chk[2001][2001];
int N;
int dfs(int left, int right) {
	if (left == N || right == N)return 0;
	if (chk[left][right])return dp[left][right];
	int re = 0;
	re = max(dfs(left + 1, right), dfs(left + 1, right + 1));
	if (card[left][0] > card[right][1])
		re = max(re, dfs(left, right + 1) + card[right][1]);
	chk[left][right] = true;
	return dp[left][right] = re;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &card[i][0]);
	for (int i = 0; i < N; i++)scanf("%d", &card[i][1]);
	printf("%d", dfs(0, 0));
	return 0;
}