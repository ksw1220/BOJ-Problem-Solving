#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N,answer;
vector<int> arr, dp;
int dfs(int now)
{
    if (dp[now]!=0)
        return dp[now];
    int re = 0;
    for (int i = now + 1; i < N; i++)
    {
        if (arr[now] > arr[i])
        {
            re = max(re,dfs(i));
        }
    }
    answer=max(answer,dp[now]=max(dp[now],re+1));
    return re+1;
}
int main()
{
    scanf("%d", &N);
    arr.assign(N, 0);
    dp.assign(N, 0);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i=0;i<N;i++){
        dfs(i);
    }
    
    printf("%d\n",answer);
    return 0;
}