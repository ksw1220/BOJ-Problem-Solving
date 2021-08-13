#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

vector<int> A, B;
map<long long, long long> m;
long long answer = 0;

void sumOfA()
{
    for (int i = 0; i < A.size(); i++)
    {
        long long sum = 0;
        for (int j = i; j < A.size(); j++)
        {
            sum += A[j];
            m[sum]++;
        }
    }
}

void sumOfB(int T)
{
    for (int i = 0; i < B.size(); i++)
    {
        long long sum = 0;
        for (int j = i; j < B.size(); j++)
        {
            sum += B[j];
            answer += m[T - sum];
        }
    }
}
int main()
{
    int T, N, M;
    scanf("%d", &T);

    scanf("%d", &N);
    A.assign(N, 0);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &M);
    B.assign(M, 0);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &B[i]);
    }

    sumOfA();
    sumOfB(T);

    printf("%lld\n", answer);
    return 0;
}