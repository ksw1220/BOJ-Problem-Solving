#include <stdio.h>

int main()
{
    int N, K;
    int numerator = 1, denominator = 1, C = 1;
    const long long P = 1000000007;
    scanf("%d %d", &N, &K);

    for (long long i = 1; i <= N; i++)
        numerator = (numerator * i) % P;
    for (long long i = 1; i <= N - K; i++)
        denominator = (denominator * i) % P;
    for (long long i = 1; i <= K; i++)
        denominator = (denominator * i) % P;

    long long idx = P - 2;
    long long mul = denominator, result = 1;

    while (idx)
    {
        if (idx % 2)
        {
            result = result * mul % P;
        }
        mul = mul * mul % P;
        idx /= 2;
    }
    long long answer = numerator * result % P;
    printf("%lld\n", answer);
    return 0;
}