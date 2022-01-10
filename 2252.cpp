#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> indegree;
vector<vector<int>> graph;
queue<int> que;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, a, b;

    cin >> N >> M;
    indegree.assign(N + 1, 0);
    graph.assign(N + 1, vector<int>(0, 0));

    while (M--)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!indegree[i])
        {
            que.push(i);
        }
    }

    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        cout << now << " ";

        for (int i = 0; i < graph[now].size(); i++)
        {
            int to = graph[now][i];
            indegree[to]--;
            if (!indegree[to])
            {
                que.push(to);
            }
        }
    }
    cout << endl;
    return 0;
}