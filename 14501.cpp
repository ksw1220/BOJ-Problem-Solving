#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[25];
struct table {
	int start, end, profit;
};
table Time[16];
bool myfunc(table a, table b) {
	if (a.end == b.end)return a.start < b.start;
	return a.end < b.end;
}
int main() {
	int N, T, P, cur = 0, ans = 0;
	scanf("%d", &N);
	Time[0] = { 0,0,0 };
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &T, &P);
		Time[i] = { i,i + T - 1,P };
	}
	sort(Time, Time + N + 1, myfunc);
	for (int i = 1; i <= N; i++) {
		if (Time[i].end > N)continue;
		int tmp = dp[Time[i].start - 1] + Time[i].profit;
		for (int j = Time[i].end; j <= N; j++)dp[j] = max(dp[j], tmp);
	}
	printf("%d", dp[N]);
	return 0;
}