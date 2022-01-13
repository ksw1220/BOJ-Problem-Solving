#include <stdio.h>
#include <vector>

using namespace std;

vector<int> arr, dp;
int main()
{
    int N, M, a, b;

    scanf("%d %d", &N, &M);
    arr.assign(N + 1, 0);
    dp.assign(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
        dp[i] = dp[i - 1] + arr[i];
    }

    while (M--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[b] - dp[a - 1]);
    }
    return 0;
}