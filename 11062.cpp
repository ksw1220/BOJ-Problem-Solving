#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int cards[1001];
int N;
int func(int left, int right, bool turn)
{
    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }
    else
    {
        if (turn)
        {
            dp[left][right] = max(func(left + 1, right, !turn) + cards[left], func(left, right - 1, !turn) + cards[right]);
        }
        else
        {
            dp[left][right] = min(func(left + 1, right, !turn), func(left, right - 1, !turn));
        }
        return dp[left][right];
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &cards[i]);
            if (N % 2)
                dp[i][i] = cards[i];
            else
                dp[i][i] = 0;
        }
        printf("%d\n", func(0, N - 1, true));
    }
    return 0;
}