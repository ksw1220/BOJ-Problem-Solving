#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<bool>> checked;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int now, bool &isTree)
{
    visited[now] = true;

    for (int i = 0; i < graph[now].size(); i++)
    {
        int next = graph[now][i];

        if (!checked[now][next])
        {
            if (visited[next])
            {
                isTree = false;
            }
            else
            {
                checked[now][next] = checked[next][now] = true;
                dfs(next, isTree);
            }
        }
    }
}
int main()
{
    int N, M, T = 0;
    int a, b;
    while (1)
    {
        T++;
        int answer = 0;
        scanf("%d %d", &N, &M);

        if (N == 0 && M == 0)
        {
            break;
        }

        checked.assign(N + 1, vector<bool>(N + 1, false));
        graph.assign(N + 1, vector<int>(0, 0));
        visited.assign(N + 1, false);
        while (M--)
        {
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                bool isTree = true;
                dfs(i, isTree);

                if (isTree)
                {
                    answer++;
                }
            }
        }

        if (answer == 0)
        {
            printf("Case %d: No trees.\n", T);
        }
        else if (answer == 1)
        {
            printf("Case %d: There is one tree.\n", T);
        }
        else
        {
            printf("Case %d: A forest of %d trees.\n", T, answer);
        }
    }
    return 0;
}