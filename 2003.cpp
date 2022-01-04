#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
int main()
{
	int N, M, input, answer = 0;
	cin >> N >> M;
	dp.assign(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> input;
		dp[i] = dp[i - 1] + input;
	}

	int l, r;
	l = r = 1;
	while (r <= N)
	{
		if (dp[r] - dp[l - 1] == M)
		{
			answer++;
			l++;
		}
		else if (dp[r] - dp[l - 1] < M)
		{
			r++;
		}
		else
		{
			l++;
		}
	}
	cout << answer << endl;
	return 0;
}