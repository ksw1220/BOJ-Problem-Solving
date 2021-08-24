#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int>> arr;
vector<vector<int>> group;
vector<vector<int>> answer;
vector<int> countGroup;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, groupNum = 0, cnt;

bool find(vector<int> v, int target)
{
    bool re = true;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == target)
        {
            re = false;
        }
    }

    return re;
}

void giveGroupNum(int x, int y)
{
    group[x][y] = groupNum;
    cnt++;

    for (int dir = 0; dir < 4; dir++)
    {
        int tox = x + dx[dir];
        int toy = y + dy[dir];

        if (tox < 0 || toy < 0 || tox >= N || toy >= M || group[tox][toy] != -1 || arr[tox][toy] == 1)
            continue;

        giveGroupNum(tox, toy);
    }
}

void giveAnswer(int x, int y)
{
    vector<int> v;
    int tmp = 1;
    for (int dir = 0; dir < 4; dir++)
    {
        int tox = x + dx[dir];
        int toy = y + dy[dir];

        if (tox < 0 || toy < 0 || tox >= N || toy >= M || !find(v, group[tox][toy]) || arr[tox][toy] == 1)
            continue;

        v.push_back(group[tox][toy]);
        tmp += countGroup[group[tox][toy]];
    }
    answer[x][y] = tmp;
}
int main()
{
    scanf("%d %d", &N, &M);
    arr.assign(N, vector<int>(M, 0));
    answer.assign(N, vector<int>(M, 0));
    group.assign(N, vector<int>(M, -1));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0 && group[i][j] == -1)
            {
                cnt = 0;
                giveGroupNum(i, j);
                countGroup.push_back(cnt);
                groupNum++;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 1)
            {
                giveAnswer(i, j);
            }
            printf("%d", answer[i][j] % 10);
        }
        printf("\n");
    }
    return 0;
}