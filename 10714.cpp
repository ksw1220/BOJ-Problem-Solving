#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long long> pieces;
vector<vector<long long>> dp;
long long getMax(int left, int right, int cnt)
{
    if (dp[left % N][right % N] != -1)
    {
        return dp[left % N][right % N];
    }
    if (cnt % 2 == 0)
    {
        if (left % N == right % N)
        {
            return dp[left % N][right % N] = pieces[left % N];
        }
        return dp[left % N][right % N] = max(getMax(left + 1, right, cnt + 1) + pieces[left % N], getMax(left, right - 1, cnt + 1) + pieces[right % N]);
    }
    else
    {
        if (left % N == right % N)
        {
            return dp[left % N][right % N] = 0;
        }
        if (pieces[left % N] > pieces[right % N])
        {
            return dp[left % N][right % N] = getMax(left + 1, right, cnt + 1);
        }
        else
        {
            return dp[left % N][right % N] = getMax(left, right - 1, cnt + 1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long answer = 0;
    cin >> N;
    pieces.resize(N);
    dp.assign(N, vector<long long>(N, -1));
    for (int i = 0; i < N; i++)
    {
        cin >> pieces[i];
    }

    for (int i = 0; i < N; i++)
    {
        answer = max(answer, getMax(i + 1, i - 1 + N, 1) + pieces[i]);
    }

    cout << answer << endl;
    return 0;
}