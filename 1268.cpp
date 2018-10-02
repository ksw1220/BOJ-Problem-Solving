#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int table[1001][1001];
bool chk[1001][1001];
int ans[1001];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)for (int j = 1; j <= 5; j++)scanf("%d", &table[i][j]);
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (j == k)continue;
				if (table[j][i] == table[k][i]) {
					if (!chk[j][k]) {
						ans[j]++;
						chk[j][k] = true;
					}
				}
			}
		}
	}
	int tmp = 0;
	for (int i = 1; i <= N; i++)tmp = max(tmp, ans[i]);
	for (int i = 1; i <= N; i++)if (tmp == ans[i]) {
		printf("%d\n", i);
		break;
	}
	return 0;
}