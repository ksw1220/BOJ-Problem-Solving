#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

vector<int> A, B;
map<int, int> cnt;
int S;
long long answer;

void dfsA(int now, int sum, int selected)
{
    if (now == A.size())
    {
        if (selected != 0)
        {
            if (sum == S)
                answer++;

            cnt[sum]++;
        }
        return;
    }
    dfsA(now + 1, sum, selected);
    dfsA(now + 1, sum + A[now], selected + 1);
}

void dfsB(int now, int sum, int selected)
{
    if (now == B.size())
    {
        if (selected != 0)
        {
            if (sum == S)
                answer++;

            answer += cnt[S - sum];
        }
        return;
    }
    dfsB(now + 1, sum, selected);
    dfsB(now + 1, sum + B[now], selected + 1);
}

int main()
{
    int N, x;
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N / 2; i++)
    {
        scanf("%d", &x);
        A.push_back(x);
    }

    for (int i = N / 2; i < N; i++)
    {
        scanf("%d", &x);
        B.push_back(x);
    }

    dfsA(0, 0, 0);
    if (B.size() != 0)
        dfsB(0, 0, 0);

    printf("%lld\n", answer);
    return 0;
}