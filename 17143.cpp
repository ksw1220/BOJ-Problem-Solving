#include <iostream>
#include <vector>
using namespace std;

typedef struct SHARK
{
    int r, c, s, d, z;
} SHARK;

int R, C, M;
vector<int> dx = {0, -1, 1, 0, 0};
vector<int> dy = {0, 0, 1, 0, -1};
vector<vector<int>> grid;
vector<SHARK> sharks;

void printGrid()
{
    cout << endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char tmp;
            if (grid[i][j] == -1)
                tmp = '.';
            else
            {
                tmp = 'A' + grid[i][j];
            }
            cout << tmp << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int catchShark(int col)
{
    int catchedShark = 0;
    for (int i = 0; i < R; i++)
    {
        if (grid[i][col] != -1)
        {
            catchedShark = sharks[grid[i][col]].z;
            sharks[grid[i][col]].z = 0;
            grid[i][col] = -1;
            break;
        }
    }
    return catchedShark;
}

void movement()
{
    vector<vector<int>> newGrid(R, vector<int>(C, -1));
    for (int i = 0; i < sharks.size(); i++)
    {
        SHARK now = sharks[i];
        if (now.z == 0)
            continue;
        int tox,toy;
        if(now.d==1||now.d==2){
            int flip=0;
            tox= now.r+dx[now.d]*now.s;
            toy=now.c;
            tox%=(2*R-2);
            if(tox<0){
                tox*=-1;
                flip++;
            }
            if(tox>=R){
                tox=2()
            }
        }
        int tox = now.r + dx[now.d] * now.s;
        int toy = now.c + dy[now.d] * now.s;
        bool flipX = false, flipY = false;
        tox %= (2 * R - 2);
        toy %= (2 * C - 2);
        if (tox < 0)
        {
            tox*=-1;
            flipX = !flipX;
        }
        if (toy < 0)
        {
            toy*=-1;
            flipY = !flipY;
        }
        if (tox >= R)
        {
            tox = 2 * R - 2 - tox;
            flipX = !flipX;
        }
        if (toy >= C)
        {
            toy = 2 * C - 2 - toy;
            flipY = !flipY;
        }
        if (flipX)
            sharks[i].d = sharks[i].d == 1 ? 2 : 1;
        else if (flipY)
            sharks[i].d = sharks[i].d == 3 ? 4 : 3;

        sharks[i].r = tox;
        sharks[i].c = toy;
        if (newGrid[tox][toy] == -1)
        {
            newGrid[tox][toy] = i;
        }
        else
        {
            int prevSharkIdx = newGrid[tox][toy];
            if (now.z > sharks[prevSharkIdx].z)
            {
                newGrid[tox][toy] = now.z;
                sharks[prevSharkIdx].z = 0;
            }
            else
            {
                sharks[i].z = 0;
            }
        }
    }
    grid = newGrid;
}
int r, c, s, d, z;
int main()
{
    int answer = 0;
    cin >> R >> C >> M;

    grid.assign(R, vector<int>(C, -1));

    for (int i = 0; i < M; i++)
    {
        cin >> r >> c >> s >> d >> z;
        grid[r - 1][c - 1] = i;
        sharks.push_back({r - 1, c - 1, s, d, z});
    }

    printGrid();
    for (int i = 0; i < C; i++)
    {
        answer += catchShark(i);
        movement();
        cout << answer << endl;
        printGrid();
    }
    cout << answer << endl;
    return 0;
}