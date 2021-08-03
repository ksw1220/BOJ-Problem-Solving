#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

vector<int> select;
vector<bool> checked, visited;
stack<int> track;
int answer = 0;
void init(int N)
{
    select.assign(N + 1, 0);
    checked.assign(N + 1, false);
    visited.assign(N + 1, false);
    answer = 0;
}
void dfs(int now)
{
    checked[now] = true;

    track.push(now);
    int next = select[now];

    if (visited[next])
    {
        while (!track.empty())
        {
            visited[track.top()] = true;
            answer++;
            track.pop();
        }
    }
    else if (checked[next])
    {
        while (!track.empty())
        {
            int top = track.top();
            visited[top] = true;
            track.pop();
            if (top == next)
                break;
        }
        while (!track.empty())
        {
            visited[track.top()] = true;
            answer++;
            track.pop();
        }
    }
    else
    {
        dfs(next);
    }

    checked[now] = false;
}
int main()
{
    int T, N;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d", &N);

        init(N);
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &select[i]);
        }

        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }

        printf("%d\n", answer);
    }
    return 0;
}