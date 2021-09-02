#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> A;
vector<pair<int, int>> unions;
vector<vector<bool>> visited;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int N, L, R, cnt = 0;

void makeUnion(int x, int y)
{
    visited[x][y] = true;
    unions.push_back({x, y});

    for (int dir = 0; dir < 4; dir++)
    {
        int tox = x + dx[dir];
        int toy = y + dy[dir];

        if (tox < 0 || toy < 0 || tox >= N || toy >= N || visited[tox][toy])
            continue;

        int diff = A[tox][toy] - A[x][y];
        diff = diff > 0 ? diff : diff * -1;

        if (L <= diff && diff <= R)
        {
            makeUnion(tox, toy);
        }
    }
}

void movement()
{
    int sum = 0;

    for (int i = 0; i < unions.size(); i++)
    {
        sum += A[unions[i].first][unions[i].second];
    }

    int avg = sum / unions.size();

    for (int i = 0; i < unions.size(); i++)
    {
        A[unions[i].first][unions[i].second] = avg;
    }
}
bool migration()
{
    bool re = false;
    visited.assign(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                unions.clear();
                makeUnion(i, j);

                if (unions.size() > 1)
                {
                    re = true;
                    movement();
                }
            }
        }
    }

    return re;
}
int main()
{
    int answer = 0;
    scanf("%d %d %d", &N, &L, &R);
    A.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    while (migration())
    {
        answer++;
    }

    printf("%d\n", answer);
    return 0;
}