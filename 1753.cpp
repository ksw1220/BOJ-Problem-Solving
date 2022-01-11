#include <stdio.h>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

class Node
{
public:
	int node, weight;
	Node(int n, int w)
	{
		this->node = n;
		this->weight = w;
	}
	bool operator<(const Node n) const
	{
		return weight > n.weight;
	}
};

vector<vector<pair<int, int>>> graph;
priority_queue<Node> pq;
vector<int> dist;
int main()
{
	int V, E, K, u, v, w;
	scanf("%d %d", &V, &E);
	scanf("%d", &K);

	graph.resize(V + 1);
	dist.assign(V + 1, INF);
	while (E--)
	{
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back({v, w});
	}

	pq.push(Node(K, 0));
	dist[K] = 0;

	while (!pq.empty())
	{
		int now = pq.top().node;
		pq.pop();

		for (int i = 0; i < graph[now].size(); i++)
		{
			int to = graph[now][i].first;
			int toDist = graph[now][i].second + dist[now];

			if (dist[to] > toDist)
			{
				dist[to] = toDist;
				pq.push(Node(to, toDist));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
		{
			printf("INF\n");
		}
		else
		{
			printf("%d\n", dist[i]);
		}
	}
	return 0;
}