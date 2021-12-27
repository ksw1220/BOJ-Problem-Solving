#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> A, pre, dp, now;
stack<int> answer;
int main()
{
    int N;
    cin >> N;
    A.assign(N, 0);
    pre.assign(N, -1);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    dp.push_back(A[0]);
    now.push_back(0);
    for (int i = 1; i < N; i++)
    {
        int idx = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        if (idx == dp.size())
        {
            dp.push_back(A[i]);
            now.push_back(i);
        }
        else
        {
            dp[idx] = A[i];
            now[idx] = i;
        }
        if (idx == 0)
        {
            pre[i] = -1;
        }
        else
        {
            pre[i] = now[idx - 1];
        }
    }
    int idx = now[now.size() - 1];
    while (idx != -1)
    {
        answer.push(A[idx]);
        idx = pre[idx];
    }

    cout << dp.size() << endl;
    while (!answer.empty())
    {
        cout << answer.top() << " ";
        answer.pop();
    }
    cout << endl;
    return 0;
}