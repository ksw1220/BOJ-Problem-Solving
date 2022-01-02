#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> numbers;
vector<vector<int>> dp;

int makeExp(int equality)
{
    int re = 0;
    dp[0][numbers[0]] = 1;
    for (int i = 1; i < equality; i++)
    {
        int val = numbers[i];
        for (int j = 0; j <= 20; j++)
        {
            if (j + val <= 20)
            {
                printf("a");
                dp[i][j + val] = dp[i - 1][j];
            }
            if (j - val >= 0)
            {
                dp[i][j - val] = dp[i - 1][j];
            }
        }
    }
    dp[equality][numbers[equality]] = 1;
    for (int i = equality + 1; i < N; i++)
    {
        int val = numbers[i];
        for (int j = 0; j <= 20; j++)
        {
            if (j + val <= 20)
            {
                dp[i][j + val] = dp[i - 1][j];
            }
            if (j - val >= 0)
            {
                dp[i][j - val] = dp[i - 1][j];
            }
        }
    }

    for (int i = 0; i <= 20; i++)
    {
        re += dp[equality - 1][i] * dp[N - 1][i];
    }

    cout << "equl " << equality << endl;
    for (int i = 0; i <= 20; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return re;
}
int main()
{
    int answer = 0;
    cin >> N;
    numbers.assign(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    for (int i = 1; i < N; i++)
    {
        dp.assign(N, vector<int>(21, 0));
        answer += makeExp(i);
    }

    cout << answer << endl;
    return 0;
}