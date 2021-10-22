#include <iostream>
#include <vector>
using namespace std;

typedef struct FIREBALL
{
    int r, c, m, s, d;
} FIREBALL;

vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};
vector<FIREBALL> fireBalls;
vector<vector<vector<FIREBALL>>> board;
int N;
void move()
{
    board.assign(N + 1, vector<vector<FIREBALL>>(N + 1, vector<FIREBALL>(0, {0, 0, 0, 0, 0})));
    for (int i = 0; i < fireBalls.size(); i++)
    {
        int tox = (fireBalls[i].r + dx[fireBalls[i].d] * fireBalls[i].s) % N;
        int toy = (fireBalls[i].c + dy[fireBalls[i].d] * fireBalls[i].s) % N;
        if (tox == 0)
            tox = N;
        if (toy == 0)
            toy = N;
        if (tox < 0)
            tox += N;
        if (toy < 0)
            toy += N;

        board[tox][toy].push_back({tox, toy, fireBalls[i].m, fireBalls[i].s, fireBalls[i].d});
    }
}

void mergeAndSplit()
{
    vector<FIREBALL> nextFireBalls;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (board[i][j].size() > 1)
            {
                int nextM = 0, nextS = 0;
                int nextD = board[i][j][0].d % 2;
                bool isSame = true;
                for (int k = 0; k < board[i][j].size(); k++)
                {
                    nextM += board[i][j][k].m;
                    nextS += board[i][j][k].s;
                    if (nextD != board[i][j][k].d % 2)
                        isSame = false;
                }
                nextM = nextM / 5;
                nextS = nextS / board[i][j].size();
                if (nextM == 0)
                    continue;
                int dir = 0;
                if (!isSame)
                    dir++;
                for (; dir < 8; dir += 2)
                {
                    nextFireBalls.push_back({i, j, nextM, nextS, dir});
                }
            }
            else if (board[i][j].size() == 1)
            {
                nextFireBalls.push_back(board[i][j][0]);
            }
        }
    }
    fireBalls = nextFireBalls;
}
int main()
{
    int M, K;
    cin >> N >> M >> K;
    fireBalls.resize(M);

    for (int i = 0; i < M; i++)
    {
        cin >> fireBalls[i].r >> fireBalls[i].c >> fireBalls[i].m >> fireBalls[i].s >> fireBalls[i].d;
    }

    int answer = 0;
    while (K--)
    {
        move();
        mergeAndSplit();

        for (int i = 0; i < fireBalls.size(); i++)
        {
            answer += fireBalls[i].m;
        }
    }
    cout << answer << endl;
    return 0;
}