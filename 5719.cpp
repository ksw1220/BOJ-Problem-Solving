#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N;
class Data
{
public:
    int node, dist;

    bool operator<(const Data &d) const
    {
        return dist > d.dist;
    }
};
vector<vector<int>> graph;
vector<int> dist, pre;

int Dijkstra(int start, int end)
{
    priority_queue<Data> pq;
    dist.assign(N, INF);
    dist[start] = 0;
    pre[start] = -1;
    pq.push({start, 0});

    while (!pq.empty())
    {
        int now = pq.top().node;
        int nowDist = pq.top().dist;
        pq.pop();

        for (int i = 0; i < N; i++)
        {
            if (graph[now][i] != INF)
            {
                int toDist = nowDist + graph[now][i];
                if (dist[i] > toDist)
                {
                    dist[i] = toDist;
                    pre[i] = now;
                    pq.push({i, toDist});
                }
            }
        }
    }

    return dist[end];
}

void deletePath(int end)
{
    queue<int> que;
    que.push(end);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();

        for (int i = 0; i < N; i++)
        {
            if (graph[i][now] != INF && dist[now] == dist[i] + graph[i][now])
            {
                graph[i][now] = INF;
                que.push(i);
            }
        }
    }
}
int main()
{
    int M, S, D, U, V, P, answer;

    while (1)
    {
        cin >> N >> M;
        if (N == 0 && M == 0)
        {
            break;
        }

        graph.assign(N, vector<int>(N, INF));
        pre.resize(N);
        cin >> S >> D;
        for (int i = 0; i < M; i++)
        {
            cin >> U >> V >> P;
            graph[U][V] = P;
        }

        answer = Dijkstra(S, D);
        if (answer == INF)
        {
            cout << -1 << endl;
            continue;
        }
        deletePath(D);
        answer = Dijkstra(S, D);

        if (answer == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << answer << endl;
        }
    }
    return 0;
}