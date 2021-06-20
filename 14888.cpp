#include <stdio.h>

#define INF 987654321
int arr[12], op[4], eval[12];
int min_v = INF, max_v = -INF, N;

int calculate()
{
    int acc = arr[0];
    for (int i = 1; i < N; i++)
    {
        if (eval[i] == 0)
        {
            acc += arr[i];
        }
        else if (eval[i] == 1)
        {
            acc -= arr[i];
        }
        else if (eval[i] == 2)
        {
            acc *= arr[i];
        }
        else if (eval[i] == 3)
        {
            acc /= arr[i];
        }
    }
    return acc;
}
void dfs(int cnt)
{
    if (cnt == N)
    {
        int tmp = calculate();
        if (tmp > max_v)
            max_v = tmp;
        if (tmp < min_v)
            min_v = tmp;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (op[i] > 0)
        {
            op[i]--;
            eval[cnt] = i;
            dfs(cnt + 1);
            op[i]++;
        }
    }
}
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &op[i]);
    }
    dfs(1);
    printf("%d\n%d\n", max_v, min_v);
    return 0;
}