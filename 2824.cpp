#include <iostream>
#include <vector>
#define MAX 1000000000
using namespace std;

vector<long long> A, B;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    int N, M;
    long answer = 1;
    bool chk = false;
    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cin >> M;
    B.assign(M, 0);
    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            long long tmp = gcd(A[i], B[j]);
            answer *= tmp;
            if (answer >= MAX)
            {
                answer %= MAX;
                chk = true;
            }
            A[i] /= tmp;
            B[j] /= tmp;
        }
    }

    if (chk)
    {
        cout.width(9);
        cout.fill('0');
        cout << answer << endl;
    }
    else
    {
        cout << answer << endl;
    }
    return 0;
}