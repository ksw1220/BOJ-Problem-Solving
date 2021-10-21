#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> field, nutrient;
vector<vector<vector<int>>> tree;
vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};

int N, treeCount;
void springAndSummer()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int k;
            vector<int> nextTree;
            // spring
            for (k = 0; k < tree[i][j].size(); k++)
            {
                int treeAge = tree[i][j][k];
                if (field[i][j] >= treeAge)
                {
                    field[i][j] -= treeAge;
                    nextTree.push_back(treeAge + 1);
                }
                else
                    break;
            }

            // summer
            for (; k < tree[i][j].size(); k++)
            {
                int treeAge = tree[i][j][k];
                field[i][j] += treeAge / 2;
            }

            // sort(nextTree.begin(), nextTree.end());
            tree[i][j] = nextTree;
        }
    }
}
void fall()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int k;
            for (k = 0; k < tree[i][j].size(); k++)
            {
                int treeAge = tree[i][j][k];
                if (tree[i][j][k] % 5 == 0)
                {
                    for (int dir = 0; dir < 8; dir++)
                    {
                        int tox = i + dx[dir];
                        int toy = j + dy[dir];
                        if (tox <= 0 || toy <= 0 || tox > N || toy > N)
                            continue;
                        tree[tox][toy].push_back(1);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            sort(tree[i][j].begin(), tree[i][j].end());
        }
    }
}

void winter()
{
    treeCount = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            field[i][j] += nutrient[i][j];
            treeCount += tree[i][j].size();
        }
    }
}
int main()
{
    int M, K;
    int x, y, z;
    cin >> N >> M >> K;
    field.assign(N + 1, vector<int>(N + 1, 5));
    nutrient.assign(N + 1, vector<int>(N + 1, 0));
    tree.assign(N + 1, vector<vector<int>>(N + 1, vector<int>(0, 0)));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> nutrient[i][j];
        }
    }
    while (M--)
    {
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }

    while (K--)
    {

        springAndSummer();
        fall();
        winter();
        }
    cout << treeCount << endl;
    return 0;
}