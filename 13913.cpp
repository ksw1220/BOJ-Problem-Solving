#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int answerCnt = INF;
vector<int> answer;
vector<int> dp(200000, INF);
queue<pair<int, vector<int>>> que;
int main()
{
    int N, K;
    cin >> N >> K;

    que.push({N, {N}});
    dp[N] = 1;
    while (!que.empty())
    {
        int now = que.front().first;
        vector<int> nowTrace = que.front().second;
        que.pop();
        if (now == K)
        {
            if (answerCnt > nowTrace.size())
            {
                answerCnt = nowTrace.size();
                answer = nowTrace;
            }
            continue;
        }
        else if (nowTrace.size() > answerCnt)
        {
            continue;
        }
        else if (now > K)
        {
            int nowCnt = nowTrace.size() + now - K;
            if (answerCnt > nowCnt)
            {
                answerCnt = nowCnt;
                answer = nowTrace;
            }
            continue;
        }
        else
        {
            if (now * 2 <= 200000 && dp[now * 2] > nowTrace.size() + 1)
            {
                nowTrace.push_back(now * 2);
                dp[now * 2] = nowTrace.size();
                que.push({now * 2, nowTrace});
                nowTrace.pop_back();
            }
            if (now < 100000 && dp[now + 1] > nowTrace.size() + 1)
            {
                nowTrace.push_back(now + 1);
                dp[now + 1] = nowTrace.size();
                que.push({now + 1, nowTrace});
                nowTrace.pop_back();
            }
            if (now > 0 && dp[now - 1] > nowTrace.size() + 1)
            {
                nowTrace.push_back(now - 1);
                dp[now - 1] = nowTrace.size();
                que.push({now - 1, nowTrace});
                nowTrace.pop_back();
            }
        }
    }
    cout << answerCnt - 1 << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    if (answerCnt != answer.size())
    {
        for (int i = answer[answer.size() - 1] - 1; i >= K; i--)
        {
            cout << i << " ";
        }
    }

    return 0;
}