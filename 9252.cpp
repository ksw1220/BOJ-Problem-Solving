#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
int dp[1001][1001];
stack<char> ans;
int main() {
	string A, B;
	cin >> A >> B;
	int a = A.length(); int b = B.length();
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (A[i] == B[j])dp[i + 1][j + 1] = dp[i][j] + 1;
			else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}
	int nowx, nowy;
	nowx = a, nowy = b;
	while (1) {
		if (dp[nowx][nowy] == 0)break;
		if (dp[nowx][nowy] == dp[nowx][nowy - 1]) {
			nowy--;
		}
		else if (dp[nowx][nowy] == dp[nowx - 1][nowy]) {
			nowx--;
		}
		else {
			nowx--;
			nowy--;
			ans.push(A[nowx]);
		}
	}
	printf("%d\n", dp[a][b]);
	while (!ans.empty()) {
		printf("%c", ans.top());
		ans.pop();
	}
	return 0;
}