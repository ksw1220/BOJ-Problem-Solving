#include <stdio.h>

int main()
{
    int N, L;
    bool check = false;
    scanf("%d %d", &N, &L);

    for (int len = L; len <= 100; len++)
    {
        int sum = len * (len - 1) / 2;
        if (sum > N)
        {
            break;
        }
        if ((N - sum) % len == 0)
        {
            int Q = (N - sum) / len;

            for (int i = 0; i < len; i++)
            {
                printf("%d ", i + Q);
            }
            check = true;
            break;
        }
    }
    if (!check)
    {
        printf("-1\n");
    }
    return 0;
}