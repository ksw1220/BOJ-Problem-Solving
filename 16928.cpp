#include <stdio.h>
#include <string.h>

#define INF 987654321
int portal[101];
int dp[101];
void dfs(int now, int cnt, int &answer)
{
    if (dp[now] < cnt)
        return;
    dp[now] = cnt;
    if (now == 100)
    {
        answer = cnt;
        return;
    }
    if (portal[now] != 0)
    {
        dfs(portal[now], cnt, answer);
        return;
    }
    for (int i = 1; i <= 6; i++)
    {
        int to = now + i;
        if (dp[to] <= cnt + 1)
            continue;
        dp[to] = cnt + 1;
        dfs(to, cnt + 1, answer);
    }
}
int main()
{
    int N, M;
    int start, end, answer = INF;

    for (int i = 0; i <= 100; i++)
        dp[i] = INF;
    scanf("%d %d", &N, &M);

    N += M;
    while (N--)
    {
        scanf("%d %d", &start, &end);
        portal[start] = end;
    }
    dfs(1, 0, answer);
    printf("%d", answer);
    return 0;
}