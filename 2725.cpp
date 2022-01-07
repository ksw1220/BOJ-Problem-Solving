#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

vector<int> dp;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int C, N;
    cin >> C;
    dp.assign(MAX, 0);
    dp[1] = 3;
    for (int i = 2; i <= MAX; i++)
    {
        int cnt = 0;
        for (int j = 1; j < i; j++)
        {
            if (gcd(i, j) == 1)
            {
                cnt++;
            }
        }
        dp[i] = dp[i - 1] + cnt * 2;
    }
    while (C--)
    {
        cin >> N;
        cout << dp[N] << endl;
    }
    return 0;
}