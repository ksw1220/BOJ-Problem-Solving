#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> indegree, cost, dp;
vector<vector<int>> graph;
queue<pair<int, int>> que;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, a;
	cin >> N;
	indegree.assign(N + 1, false);
	cost.assign(N + 1, 0);
	dp.assign(N + 1, 0);
	graph.assign(N + 1, vector<int>(0, 0));

	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i];
		while (1)
		{
			cin >> a;
			if (a == -1)
			{
				break;
			}
			else
			{
				indegree[i]++;
				graph[a].push_back(i);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (!indegree[i])
		{
			dp[i] = cost[i];
			que.push({i, cost[i]});
		}
	}

	while (!que.empty())
	{
		int now = que.front().first;
		int nowCost = que.front().second;
		que.pop();

		for (int i = 0; i < graph[now].size(); i++)
		{
			int to = graph[now][i];
			int toCost = nowCost + cost[to];
			if (dp[to] < toCost)
			{
				dp[to] = toCost;
				que.push({to, toCost});
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << dp[i] << endl;
	}
	return 0;
}