#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<int>>> adj;
vector<bool> visited;
void dfs(int now, int dir, int &cnt)
{
	for (int i = 0; i < adj[dir][now].size(); i++)
	{
		int next = adj[dir][now][i];
		if (!visited[next])
		{
			visited[next] = true;
			cnt++;
			dfs(next, dir, cnt);
		}
	}
}
int main()
{
	int N, M, a, b;
	cin >> N >> M;

	adj.assign(2, vector<vector<int>>(N + 1, vector<int>(0, 0)));

	while (M--)
	{
		cin >> a >> b;
		adj[0][a].push_back(b);
		adj[1][b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		int count = 0;
		visited.assign(N + 1, false);
		visited[i] = true;
		dfs(i, 0, count);
		dfs(i, 1, count);

		cout << N - count - 1 << endl;
	}
	return 0;
}