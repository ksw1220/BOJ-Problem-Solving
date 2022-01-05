#include <iostream>
#include <vector>
#include <queue>
#define MAXNUM 14
using namespace std;

vector<vector<int>> tree;
vector<int> indegree, outdegree;

bool isTree(int root)
{
    queue<int> que;
    vector<bool> visited;
    visited.assign(MAXNUM, false);

    que.push(root);
    visited[root] = true;

    while (!que.empty())
    {
        int now = que.front();
        que.pop();

        for (int i = 0; i < tree[now].size(); i++)
        {
            int to = tree[now][i];
            if (visited[to])
            {
                return false;
            }
            else
            {
                visited[to] = true;
                que.push(to);
            }
        }
    }
    return true;
}
int getRoot()
{
    int root = 0;
    for (int i = 1; i <= MAXNUM; i++)
    {
        if (indegree[i] == 0 && outdegree[i] != 0)
        {
            if (root == 0)
            {
                root = i;
            }
            else
            {
                root = -1;
                break;
            }
        }
    }

    return root;
}
int main()
{
    int u, v;
    for (int iter = 0;; iter++)
    {
        bool chk = true;
        cin >> u >> v;
        if (u == -1 && v == -1)
        {
            break;
        }
        else if (u == 0 && v == 0)
        {
            cout << "Case " << iter + 1 << " is a tree." << endl;
            continue;
        }
        int root = 0;
        tree.assign(MAXNUM, vector<int>(0, 0));
        indegree.assign(MAXNUM, 0);
        outdegree.assign(MAXNUM, 0);
        tree[u].push_back(v);
        indegree[v]++;
        outdegree[u]++;
        while (1)
        {
            cin >> u >> v;
            if (u == 0 && v == 0)
            {
                break;
            }
            tree[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }
        root = getRoot();
        if (root == 0 || root == -1)
        {
            cout << "Case " << iter + 1 << " is not a tree." << endl;
            continue;
        }

        if (isTree(root))
        {
            cout << "Case " << iter + 1 << " is a tree." << endl;
        }
        else
        {
            cout << "Case " << iter + 1 << " is not a tree." << endl;
        }
    }
    return 0;
}