#include <stdio.h>
#include <vector>

#define MOD 1000000007
using namespace std;

long long power(long long a)
{
    long long cnt = MOD - 2;
    long long tmp = a;
    long long re = 1;
    while (cnt)
    {
        if (cnt % 2)
            re = re * tmp % MOD;
        tmp = tmp * tmp % MOD;
        cnt /= 2;
    }
    return re;
}
int main()
{
    int M, N, S;
    long long answer = 0;
    vector<int> vecN, vecS;
    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &N, &S);
        vecN.push_back(N);
        vecS.push_back(S);
    }

    for (int i = 0; i < M; i++)
    {
        answer = (answer + vecS[i] * power(vecN[i])) % MOD;
    }
    printf("%lld\n", answer);
    return 0;
}