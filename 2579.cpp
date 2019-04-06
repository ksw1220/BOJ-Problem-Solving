#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[301], dp[301][2];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)scanf("%d", &arr[i]);
	dp[0][0] = dp[0][1] = 0;
	dp[1][0] = arr[1], dp[1][1] = 0;
	dp[2][0] = arr[1] + arr[2], dp[2][1] = arr[2];
	for (int i = 3; i <= N; i++) {
		dp[i][0] = dp[i - 1][1] + arr[i];
		dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + arr[i];
	}
	printf("%d", max(dp[N][0], dp[N][1]));
	return 0;
}