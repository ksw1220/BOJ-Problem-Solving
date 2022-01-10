#include <iostream>
#include <vector>

using namespace std;

vector<int> in, out;
vector<bool> visited;
vector<vector<vector<int>>> graph;
void outDfs(int x, int now)
{
    for (int i = 0; i < graph[now][0].size(); i++)
    {
        int to = graph[now][0][i];
        if (!visited[to])
        {
            visited[to] = true;
            out[x]++;
            outDfs(x, to);
        }
    }
}
void inDfs(int x, int now)
{
    for (int i = 0; i < graph[now][1].size(); i++)
    {
        int to = graph[now][1][i];
        if (!visited[to])
        {
            visited[to] = true;
            in[x]++;
            inDfs(x, to);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, a, b, answer = 0;
    cin >> N >> M;
    in.assign(N + 1, 0);
    out.assign(N + 1, 0);
    graph.assign(N + 1, vector<vector<int>>(2, vector<int>(0, 0)));
    while (M--)
    {
        cin >> a >> b;
        graph[a][0].push_back(b);
        graph[b][1].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        visited.assign(N + 1, false);
        visited[i] = true;
        outDfs(i, i);
        visited.assign(N + 1, false);
        visited[i] = true;
        inDfs(i, i);
        if (in[i] + out[i] == N - 1)
        {
            answer++;
        }
    }

    cout << answer << endl;
    return 0;
}