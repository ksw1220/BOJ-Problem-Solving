#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> dy = {0, -1, -1, -1, 0, 1, 1, 1};
typedef vector<vector<vector<int>>> SPACE;
typedef vector<pair<int, int>> FISH_ORDER;

void dfs(int acc, SPACE space, FISH_ORDER fishOrder, vector<bool> isAlive, int x, int y)
{
    answer = answer > acc ? answer : acc;
    for (int i = 1; i < fishOrder.size(); i++)
    {
        pair<int, int> now = fishOrder[i];
        if (!isAlive[i])
            continue;
        pair<int, int> next;
        int dir = space[now.first][now.second][1];
        next.first = now.first + dx[dir];
        next.second = now.second + dy[dir];

        while (next.first < 0 || next.second < 0 || next.first > 3 || next.second > 3 || (next.first == x && next.second == y))
        {
            dir = (dir + 1) % 8;
            next.first = now.first + dx[dir];
            next.second = now.second + dy[dir];
        }

        space[now.first][now.second][1] = dir;
        int nowNum = space[now.first][now.second][0];
        int nowDir = space[now.first][now.second][1];
        int nextNum = space[next.first][next.second][0];
        int nextDir = space[next.first][next.second][1];
        space[now.first][now.second][0] = nextNum;
        space[now.first][now.second][1] = nextDir;
        space[next.first][next.second][0] = nowNum;
        space[next.first][next.second][1] = nowDir;

        fishOrder[nowNum] = next;
        fishOrder[nextNum] = now;
    }

    for (int i = 1; i <= 3; i++)
    {
        int sharkDir = space[x][y][1];
        int tox = x + dx[sharkDir] * i;
        int toy = y + dy[sharkDir] * i;
        if (tox < 0 || toy < 0 || tox > 3 || toy > 3)
            break;
        int preyNum = space[tox][toy][0];
        if (!isAlive[preyNum])
            continue;
        isAlive[preyNum] = false;
        dfs(acc + preyNum, space, fishOrder, isAlive, tox, toy);
        isAlive[preyNum] = true;
    }
}
int main()
{
    SPACE initialSpace(4, vector<vector<int>>(4, vector<int>(2, 0)));
    FISH_ORDER initialFishOrder(17, {0, 0});
    vector<bool> isAlive(17, true);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> initialSpace[i][j][0] >> initialSpace[i][j][1];
            initialSpace[i][j][1]--;
            initialFishOrder[initialSpace[i][j][0]] = {i, j};
        }
    }
    int startNumber = initialSpace[0][0][0];
    isAlive[startNumber] = false;
    dfs(startNumber, initialSpace, initialFishOrder, isAlive, 0, 0);

    cout << answer << endl;
    return 0;
}