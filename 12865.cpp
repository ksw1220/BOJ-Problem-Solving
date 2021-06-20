#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct stuff
{
    int w, v;
} S;

bool myfunction(stuff a, stuff b)
{
    return a.w < b.w;
}
int dp[101][100001];
int main()
{
    int N, K;
    vector<stuff> stuffs;
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
    {
        stuff tmp;
        scanf("%d %d", &tmp.w, &tmp.v);
        stuffs.push_back(tmp);
    }

    sort(stuffs.begin(), stuffs.end(), myfunction);

    for (int i = 1; i <= N; i++)
    {
        int weight = stuffs[i - 1].w;
        int value = stuffs[i - 1].v;

        for (int j = 0; j <= K; j++)
        {
            if (weight <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    printf("%d\n", dp[N][K]);
    return 0;
}