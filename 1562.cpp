#include <iostream>
#include <vector>

#define MOD 1000000000
using namespace std;
vector<vector<vector<long long>>> dp;
int main()
{
    int N;
    long long answer = 0;
    cin >> N;
    dp.assign(N + 1, vector<vector<long long>>(10, vector<long long>(1024, 0)));

    for (int i = 1; i < 10; i++)
    {
        dp[1][i][1 << i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 1; k < 1024; k++)
            {
                if (j == 0)
                {
                    dp[i][0][k | 1 << 0] += dp[i - 1][1][k] % MOD;
                }
                else if (j == 9)
                {
                    dp[i][9][k | 1 << 9] += dp[i - 1][8][k] % MOD;
                }
                else
                {
                    dp[i][j][k | 1 << j] += (dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]) % MOD;
                }
            }
        }
    }

    for (int j = 0; j < 10; j++)
    {
        answer = (answer + dp[N][j][1023]) % MOD;
    }

    cout << answer << endl;
    return 0;
}