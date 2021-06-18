#include <stdio.h>

int main()
{
    int N, M, a, b;
    int package = 1001, individual = 1001;
    int answer = 0;
    scanf("%d %d", &N, &M);
    while (M--)
    {
        scanf("%d %d", &a, &b);
        if (a < package)
            package = a;
        if (b < individual)
            individual = b;
    }

    if (package >= individual * 6)
    {
        answer = individual * N;
    }
    else
    {
        if (N % 6 * individual > package)
        {
            answer = N / 6 * package + package;
        }
        else
            answer = N / 6 * package + N % 6 * individual;
    }
    printf("%d\n", answer);
    return 0;
}