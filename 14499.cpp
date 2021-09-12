#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<int> dice(6, 0);
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void East()
{
    vector<int> tmpDice(6, 0);

    tmpDice[0] = dice[5];
    tmpDice[1] = dice[1];
    tmpDice[2] = dice[0];
    tmpDice[3] = dice[2];
    tmpDice[4] = dice[4];
    tmpDice[5] = dice[3];

    dice = tmpDice;
}
void West()
{
    vector<int> tmpDice(6, 0);

    tmpDice[0] = dice[2];
    tmpDice[1] = dice[1];
    tmpDice[2] = dice[3];
    tmpDice[3] = dice[5];
    tmpDice[4] = dice[4];
    tmpDice[5] = dice[0];

    dice = tmpDice;
}
void South()
{
    vector<int> tmpDice(6, 0);

    tmpDice[0] = dice[1];
    tmpDice[1] = dice[3];
    tmpDice[2] = dice[2];
    tmpDice[3] = dice[4];
    tmpDice[4] = dice[0];
    tmpDice[5] = dice[5];

    dice = tmpDice;
}
void North()
{
    vector<int> tmpDice(6, 0);

    tmpDice[0] = dice[4];
    tmpDice[1] = dice[0];
    tmpDice[2] = dice[2];
    tmpDice[3] = dice[1];
    tmpDice[4] = dice[3];
    tmpDice[5] = dice[5];

    dice = tmpDice;
}
int main()
{
    int N, M, x, y, K;
    cin >> N >> M >> x >> y >> K;

    map.assign(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    int dir;
    while (K--)
    {
        cin >> dir;
        int tox = x + dx[dir - 1];
        int toy = y + dy[dir - 1];

        if (tox < 0 || toy < 0 || tox >= N || toy >= M)
            continue;

        x = tox;
        y = toy;

        if (dir == 1)
            East();
        else if (dir == 2)
            West();
        else if (dir == 3)
            North();
        else
            South();

        if (!map[x][y])
        {
            map[x][y] = dice[3];
        }
        else
        {
            dice[3] = map[x][y];
            map[x][y] = 0;
        }

        cout << dice[0] << endl;
    }
    return 0;
}