#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_COST 100000
using namespace std;

vector<int> cost, memory;
vector<vector<int>> dp;
int main()
{
    int N, M;

    cin >> N >> M;
    cost.resize(N + 1);
    memory.resize(N + 1);
    dp.assign(N + 1, vector<int>(MAX_COST + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        cin >> memory[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= MAX_COST; j++)
        {
            if (j >= cost[i])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (int i = 0; i <= MAX_COST; i++)
    {
        if (dp[N][i] >= M)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}