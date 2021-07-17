#include <stdio.h>
#include <vector>

#define INF 987654321
using namespace std;

vector<int> answer;
vector<int> dp, tmp;
void dfs(int now, int cnt, vector<int> &acc)
{
    acc.push_back(now);
    dp[now] = cnt;
    if (now == 1)
    {
        if (answer.size() == 0 || answer.size() > acc.size())
        {
            answer = acc;
        }
    }
    else
    {
        if (now % 3 == 0 && dp[now / 3] > cnt + 1)
        {
            dfs(now / 3, cnt + 1, acc);
        }
        if (now % 2 == 0 && dp[now / 2] > cnt + 1)
        {
            dfs(now / 2, cnt + 1, acc);
        }
        if (dp[now - 1] > cnt + 1)
        {
            dfs(now - 1, cnt + 1, acc);
        }
    }
    acc.pop_back();
}
int main()
{
    int N;
    scanf("%d", &N);

    dp.assign(N + 1, INF);
    dfs(N, 0, tmp);

    printf("%lu\n", answer.size() - 1);
    for (int i = 0; i < answer.size(); i++)
    {
        printf("%d ", answer[i]);
    }
    return 0;
}