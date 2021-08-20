#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<pair<int, int>> matrixs;
vector<vector<int>> dp;

int multiple(int left, int right)
{
    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }

    int re = INF;
    if (left == right)
    {
        re = 0;
    }
    else
    {
        for (int i = left; i < right; i++)
        {
            re = min(re, multiple(left, i) + multiple(i + 1, right) + matrixs[left].first * matrixs[i].second * matrixs[right].second);
        }
    }
    return dp[left][right] = re;
}
int main()
{
    int N;
    scanf("%d", &N);
    matrixs.assign(N, {0, 0});
    dp.assign(N, vector<int>(N, -1));

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &matrixs[i].first, &matrixs[i].second);
    }

    printf("%d\n", multiple(0, N - 1));

    return 0;
}