#include <stdio.h>

long long dist[100001];
long long cost[100001];
int main()
{
    int N;
    long long min, answer = 0;
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%lld", &dist[i]);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &cost[i]);
    }
    min = cost[0];
    for (int i = 0; i < N - 1; i++)
    {
        if (min > cost[i])
        {
            min = cost[i];
        }
        answer += min * dist[i];
    }

    printf("%lld", answer);
    return 0;
}