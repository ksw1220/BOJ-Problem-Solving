#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<vector<vector<int>>> dp;
vector<int> arr;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int x, answer = INF;
    arr.push_back(0);
    while (1)
    {
        cin >> x;
        if (x == 0)
        {
            break;
        }
        arr.push_back(x);
    }

    dp.resize(arr.size(), vector<vector<int>>(5, vector<int>(5, INF)));
    dp[0][0][0] = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int step = arr[i];
        for (int j = 0; j <= 4; j++)
        {
            for (int k = 0; k <= 4; k++)
            {
                if (dp[i - 1][j][k] != INF)
                {
                    if (j == 0)
                    {
                        dp[i][step][k] = min(dp[i][step][k], dp[i - 1][j][k] + 2);
                    }
                    else if (step == j)
                    {
                        dp[i][step][k] = min(dp[i][step][k], dp[i - 1][j][k] + 1);
                    }
                    else if (step % 2 != j % 2)
                    {
                        dp[i][step][k] = min(dp[i][step][k], dp[i - 1][j][k] + 3);
                    }
                    else
                    {
                        dp[i][step][k] = min(dp[i][step][k], dp[i - 1][j][k] + 4);
                    }
                    if (k == 0)
                    {
                        dp[i][j][step] = min(dp[i][j][step], dp[i - 1][j][k] + 2);
                    }
                    else if (step == k)
                    {
                        dp[i][j][step] = min(dp[i][j][step], dp[i - 1][j][k] + 1);
                    }
                    else if (step % 2 != k % 2)
                    {
                        dp[i][j][step] = min(dp[i][j][step], dp[i - 1][j][k] + 3);
                    }
                    else
                    {
                        dp[i][j][step] = min(dp[i][j][step], dp[i - 1][j][k] + 4);
                    }
                }
            }
        }
    }

    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            answer = min(answer, dp[arr.size() - 1][i][j]);
        }
    }
    
    cout << answer << endl;
    return 0;
}