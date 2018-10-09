#include<stdio.h>
int arr[10001], dp[10001];
int main() {
	int N, M, ans = 0;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)scanf("%d", &arr[i]);
	for (int i = 1; i <= N; i++)arr[i] += arr[i - 1];
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			if ((arr[j] - arr[j - i]) == M)ans++;
		}
	}
	printf("%d", ans);
	return 0;
}