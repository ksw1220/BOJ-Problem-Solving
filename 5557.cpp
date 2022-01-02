#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long> numbers;
vector<vector<long long>> dp;

long long makeExp()
{
    long long re = 0;
    dp[0][numbers[0]] = 1;
    for (int i = 1; i < N - 1; i++)
    {
        int val = numbers[i];
        for (int j = 0; j <= 20; j++)
        {
            if (dp[i - 1][j])
            {
                if (j + val <= 20)
                {
                    dp[i][j + val] += dp[i - 1][j];
                }
                if (j - val >= 0)
                {
                    dp[i][j - val] += dp[i - 1][j];
                }
            }
        }
    }

    re = dp[N - 2][numbers[N - 1]];

    return re;
}
int main()
{
    long long answer = 0;
    cin >> N;
    numbers.assign(N, 0);
    dp.assign(N, vector<long long>(21, 0));
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }

    answer = makeExp();

    cout << answer << endl;
    return 0;
}