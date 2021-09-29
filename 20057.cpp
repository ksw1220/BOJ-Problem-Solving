#include <iostream>
#include <vector>

using namespace std;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {-1, 0, 1, 0};
vector<pair<int, int>> scatter = {{-1, 1}, {1, 1}, {-2, 0}, {2, 0}, {0, -2}, {-1, 0}, {1, 0}, {-1, -1}, {1, -1}, {0, -1}};
vector<int> percent = {1, 1, 2, 2, 5, 7, 7, 10, 10, 0};
vector<vector<int>> A;
int N, answer;

void tornado(int x, int y, int dir)
{
    vector<pair<int, int>> dirScatter(10);
    int sum = 0;
    if (dir == 0)
    {
        dirScatter = scatter;
    }
    else if (dir == 1)
    {
        for (int i = 0; i < scatter.size(); i++)
        {
            dirScatter[i].first = -scatter[i].second;
            dirScatter[i].second = -scatter[i].first;
        }
    }
    else if (dir == 2)
    {
        for (int i = 0; i < scatter.size(); i++)
        {
            dirScatter[i].first = scatter[i].first;
            dirScatter[i].second = -scatter[i].second;
        }
    }
    else
    {
        for (int i = 0; i < scatter.size(); i++)
        {
            dirScatter[i].first = scatter[i].second;
            dirScatter[i].second = scatter[i].first;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        int tox = x + dirScatter[i].first;
        int toy = y + dirScatter[i].second;
        int movedAmount = A[x][y] * percent[i] / 100;

        if (i == 9)
        {
            movedAmount = A[x][y] - sum;
        }
        if (tox < 0 || toy < 0 || tox >= N || toy >= N)
        {
            answer += movedAmount;
        }
        else
        {
            A[tox][toy] += movedAmount;
        }
        sum += movedAmount;
    }

    A[x][y] = 0;
}
bool changeDir(int x, int y)
{
    bool re = false;
    if (x == y && x > N / 2)
    {
        re = true;
    }
    else if (y == N - 1 - x)
    {
        re = true;
    }
    else if (y == x - 1 && x <= N / 2)
    {
        re = true;
    }
    return re;
}
int main()
{
    cin >> N;

    A.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    int X, Y, dir = 0;
    X = Y = N / 2;

    while (X != 0 || Y != 0)
    {
        X = X + dx[dir];
        Y = Y + dy[dir];
        tornado(X, Y, dir);

        if (changeDir(X, Y))
        {
            dir = (dir + 1) % 4;
        }
    }

    cout << answer << endl;
    return 0;
}