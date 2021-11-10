#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> tree, ancestor;
vector<int> depth;
void dfs(int now, int parent)
{
    ancestor[now].push_back(parent);
    depth[now] = depth[parent] + 1;

    int cnt = 1;
    while (1)
    {
        int tmp = ancestor[now][cnt - 1];
        if (ancestor[tmp].size() < cnt)
            break;
        ancestor[now].push_back(ancestor[tmp][cnt - 1]);
        cnt++;
    }
    for (int i = 0; i < tree[now].size(); i++)
    {
        int next = tree[now][i];
        if (next != parent)
        {
            dfs(next, now);
        }
    }
}

int getLCA(int a, int b)
{
    if (depth[a] > depth[b])
    {
        swap(a, b);
    }
    int LCA = a;
    if (a != b)
    {

        int maxAncestor = ancestor[b].size() - 1;
        while (depth[a] != depth[b])
        {
            for (int i = maxAncestor; i >= 0; i--)
            {
                if (depth[a] <= depth[ancestor[b][i]])
                {
                    b = ancestor[b][i];
                }
            }
        }
    }

    if (a != b)
    {
        int maxAncestor = ancestor[a].size() - 1;

        for (int i = maxAncestor; i >= 0; i--)
        {
            if (ancestor[a][i] != ancestor[b][i])
            {
                a = ancestor[a][i];
                b = ancestor[b][i];
            }
            LCA = ancestor[a][i];
        }
    }

    return LCA;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N, M, a, b;
    cin >> N;
    tree.assign(N + 1, vector<int>(0, 0));
    ancestor.assign(N + 1, vector<int>(0, 0));
    depth.assign(N + 1, 0);
    for (int i = 1; i < N; i++)
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, 0);
    
    cin >> M;
    while (M--)
    {
        cin >> a >> b;
        cout << getLCA(a, b) << endl;
    }
    return 0;
}