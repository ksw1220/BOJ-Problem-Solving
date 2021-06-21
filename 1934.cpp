#include <stdio.h>

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int main()
{
    int T, A, B;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &A, &B);
        int tmp = gcd(A, B);
        printf("%d\n", A * B / tmp);
    }
    return 0;
}