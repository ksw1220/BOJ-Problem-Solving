#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, P, answer = INF;
vector<int> dp;
vector<vector<int>> cost;

int getCost(int bit, int target)
{
    int re = INF;
    for (int i = 0; i < N; i++)
    {
        if (bit & (1 << i))
        {
            re = min(re, cost[i][target]);
        }
    }
    return re;
}
void dfs(int bit, int cnt, int acc)
{
    if (cnt >= P)
    {
        answer = min(answer, acc);
    }
    for (int i = 0; i < N; i++)
    {
        if (!(bit & (1 << i)))
        {
            int nextBit = bit | (1 << i);
            int nextCost = acc + getCost(bit, i);
            if (dp[nextBit] > nextCost)
            {
                dp[nextBit] = nextCost;
                dfs(nextBit, cnt + 1, nextCost);
            }
        }
    }
}
int main()
{
    int cnt = 0, bitmask = 0;
    string s;
    cin >> N;
    cost.assign(N, vector<int>(N, 0));
    dp.assign(1 << N, INF);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> cost[i][j];
        }
    }

    cin >> s;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == 'Y')
        {
            bitmask |= (1 << i);
            cnt++;
        }
    }
    cin >> P;
    dp[bitmask] = 0;
    dfs(bitmask, cnt, 0);
    if (answer == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << answer << endl;
    }
    return 0;
}