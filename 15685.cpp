#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> grid(101, vector<bool>(101, false));
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, -1, 0, 1};

void dragonCurve(int g, vector<pair<int, int>> nowCurve, int nowG)
{
    if (nowG == g)
    {
        return;
    }
    else
    {
        vector<pair<int, int>> nextCurve = nowCurve;
        pair<int, int> standard = nowCurve[nowCurve.size() - 1];
        for (int i = nowCurve.size() - 2; i >= 0; i--)
        {
            // move
            int tox = nowCurve[i].first - standard.first;
            int toy = nowCurve[i].second - standard.second;

            // rotate
            int tmp = tox;
            tox = -toy;
            toy = tmp;

            // move
            tox += standard.first;
            toy += standard.second;

            grid[tox][toy] = true;
            nextCurve.push_back({tox, toy});
        }
        dragonCurve(g, nextCurve, nowG + 1);
    }
}
int main()
{
    int N, x, y, d, g, answer = 0;

    cin >> N;
    while (N--)
    {
        cin >> x >> y >> d >> g;
        int tox = x + dx[d];
        int toy = y + dy[d];
        grid[x][y] = grid[tox][toy] = true;
        dragonCurve(g, {{x, y}, {tox, toy}}, 0);
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (grid[i][j] && grid[i][j + 1] && grid[i + 1][j] && grid[i + 1][j + 1])
                answer++;
        }
    }
    cout << answer << endl;
    return 0;
}