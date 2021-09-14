#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> board;
int N;
int answer = 0;
vector<int> mergeVector(vector<int> v)
{
    queue<int> que;
    vector<int> re;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i])
            que.push(v[i]);
    }

    int now = -1;
    while (!que.empty())
    {
        int next = que.front();
        que.pop();
        if (now == -1)
        {
            now = next;
        }
        else if (now == next)
        {
            re.push_back(now * 2);
            now = -1;
        }
        else
        {
            re.push_back(now);
            now = next;
        }
    }

    if (now != -1)
    {
        re.push_back(now);
    }
    while (re.size() != N)
    {
        re.push_back(0);
    }

    return re;
}
void dfs(vector<vector<int>> B, int cnt, int dir)
{
    if (cnt == 5)
    {
        return;
    }

    vector<vector<int>> nextB(N, vector<int>(N, 0));
    if (dir == 0)
    {
        for (int i = 0; i < N; i++)
        {
            vector<int> tmp(N, 0);
            for (int j = 0; j < N; j++)
            {
                tmp[j] = B[i][j];
            }
            tmp = mergeVector(tmp);

            for (int j = 0; j < N; j++)
            {

                nextB[i][j] = tmp[j];
            }
        }
    }
    else if (dir == 1)
    {
        for (int i = 0; i < N; i++)
        {
            vector<int> tmp(N, 0);
            for (int j = 0; j < N; j++)
            {
                tmp[j] = B[j][i];
            }
            tmp = mergeVector(tmp);

            for (int j = 0; j < N; j++)
            {
                nextB[j][i] = tmp[j];
            }
        }
    }
    else if (dir == 2)
    {
        for (int i = 0; i < N; i++)
        {
            vector<int> tmp(N, 0);
            for (int j = 0; j < N; j++)
            {
                tmp[j] = B[i][N - j - 1];
            }
            tmp = mergeVector(tmp);

            for (int j = 0; j < N; j++)
            {
                nextB[i][N - j - 1] = tmp[j];
            }
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            vector<int> tmp(N, 0);
            for (int j = 0; j < N; j++)
            {
                tmp[j] = B[N - j - 1][i];
            }
            tmp = mergeVector(tmp);

            for (int j = 0; j < N; j++)
            {
                nextB[N - j - 1][i] = tmp[j];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            answer = max(answer, nextB[i][j]);
        }
    }
    for (int dir = 0; dir < 4; dir++)
    {
        dfs(nextB, cnt + 1, dir);
    }
}
int main()
{
    cin >> N;

    board.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int dir = 0; dir < 4; dir++)
    {
        dfs(board, 0, dir);
    }

    cout << answer << endl;
    return 0;
}