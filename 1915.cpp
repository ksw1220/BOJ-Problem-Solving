#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> arr, dp;
int main()
{
    int N, M;
    int ans = 0;

    scanf("%d %d", &N, &M);
    arr.assign(N + 1, vector<int>(M + 1, 0));
    dp.assign(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%1d", &arr[i][j]);
            ans = max(ans, dp[i][j] = arr[i][j]);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (arr[i][j] == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d", ans * ans);
    return 0;
}