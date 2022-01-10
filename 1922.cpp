#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge
{
public:
    int from, to;
    int weight;

    Edge(int a, int b, int c)
    {
        from = a;
        to = b;
        weight = c;
    }

    bool operator<(const Edge &edge) const
    {
        return weight > edge.weight;
    }
};

vector<int> parent;
priority_queue<Edge> pq;
void unionParents(int a, int b)
{
    parent[a] = b;
}

int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    else
    {
        return parent[x] = find(parent[x]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, a, b, c, answer = 0, cnt = 0;

    cin >> N >> M;
    for (int i = 0; i <= N; i++)
    {
        parent.push_back(i);
    }
    while (M--)
    {
        cin >> a >> b >> c;
        Edge e(a, b, c);
        pq.push(e);
    }

    while (!pq.empty())
    {
        if (cnt == N - 1)
        {
            break;
        }
        Edge now = pq.top();
        pq.pop();
        int a = find(now.from);
        int b = find(now.to);
        if (a != b)
        {
            unionParents(a, b);
            answer += now.weight;
            cnt++;
        }
    }

    cout << answer << endl;
    return 0;
}