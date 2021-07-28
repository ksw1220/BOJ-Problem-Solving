#include <stdio.h>
#include <vector>

using namespace std;

vector<int> group;
vector<vector<int>> adj;
vector<bool> visit;
void dfs(int now, int groupId, bool &answer)
{
    visit[now] = true;
    group[now] = groupId;
    if (!answer)
        return;

    for (int i = 0; i < adj[now].size(); i++)
    {
        int next = adj[now][i];
        int nextGroupId = groupId % 2 + 1;
        if (visit[next])
            continue;

        if (!group[next])
        {
            dfs(next, nextGroupId, answer);
        }
        else
        {
            if (group[next] != nextGroupId)
            {
                answer = false;
                return;
            }
        }
    }
    visit[now] = false;
}
int main()
{
    int K, V, E;
    int s, e;
    scanf("%d", &K);

    while (K--)
    {
        bool answer = true;
        scanf("%d %d", &V, &E);
        group.assign(V + 1, 0);
        adj.assign(V + 1, vector<int>(0, 0));
        visit.assign(V + 1, false);
        while (E--)
        {
            scanf("%d %d", &s, &e);
            adj[s].push_back(e);
            adj[e].push_back(s);
        }

        for (int i = 1; i <= V; i++)
        {
            if (answer && !group[i])
            {
                dfs(i, 1, answer);
            }
        }

        answer ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}