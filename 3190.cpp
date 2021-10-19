#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> board;
queue<pair<int, char>> dirInfo;
vector<pair<int, int>> snake;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
int N;
void move(int &time, int dir)
{
    if (!dirInfo.empty() && dirInfo.front().first == time)
    {
        if (dirInfo.front().second == 'L')
        {
            dir = (dir + 3) % 4;
        }
        else
        {
            dir = (dir + 1) % 4;
        }
        dirInfo.pop();
    }

    int tox = snake[0].first + dx[dir];
    int toy = snake[0].second + dy[dir];

    if (tox <= 0 || toy <= 0 || tox > N || toy > N || board[tox][toy] == 2)
    {
        return;
    }
    else
    {
        snake.insert(snake.begin(), {tox, toy});
        if (board[tox][toy] == 0)
        {
            int rmx = snake[snake.size() - 1].first;
            int rmy = snake[snake.size() - 1].second;
            board[rmx][rmy] = 0;
            snake.pop_back();
        }
        board[tox][toy] = 2;
        time++;
        move(time, dir);
    }
}

int main()
{
    int K, L, a, b, X, time = 0;
    char dir;
    cin >> N >> K;
    board.assign(N + 1, vector<int>(N + 1, 0));
    while (K--)
    {
        cin >> a >> b;
        board[a][b] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> X >> dir;
        dirInfo.push({X, dir});
    }

    board[1][1] = 2;
    snake.push_back({1, 1});

    move(time, 1);
    cout << time + 1 << endl;
}