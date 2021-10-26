#include <iostream>
#include <vector>
using namespace std;

int N;
typedef pair<int, int> BISHOP;
vector<vector<BISHOP>> candidates(2, vector<BISHOP>(0, {0, 0}));
vector<vector<BISHOP>> bishops(2, vector<BISHOP>(0, {0, 0}));
vector<int> answer(2, 0);

bool isPossible(int x, int y, int color)
{
    bool re = true;
    for (int i = 0; i < bishops[color].size(); i++)
    {
        int tox = bishops[color][i].first;
        int toy = bishops[color][i].second;
        if (x + y == tox + toy || x - y == tox - toy)
        {
            re = false;
            break;
        }
    }

    return re;
}

void dfs(int now, int cnt, int color)
{
    if (now == candidates[color].size())
    {
        answer[color] = answer[color] > cnt ? answer[color] : cnt;
        return;
    }
    int x = candidates[color][now].first;
    int y = candidates[color][now].second;

    if (isPossible(x, y, color))
    {
        bishops[color].push_back({x, y});
        dfs(now + 1, cnt + 1, color);
        bishops[color].pop_back();
    }
    dfs(now + 1, cnt, color);
}
int main()
{
    int input;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> input;
            if (input)
            {
                if ((i + j) % 2 == 0)
                    candidates[0].push_back({i, j});
                else
                    candidates[1].push_back({i, j});
            }
        }
    }

    dfs(0, 0, 0);
    dfs(0, 0, 1);

    cout << answer[0] + answer[1] << endl;
    return 0;
}