#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> arr;

bool isRoad(vector<int> v, int len)
{
    bool re = true;
    vector<bool> runway(v.size(), false);

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1] != v[i])
        {
            if (v[i] - v[i - 1] >= 2 || v[i - 1] - v[i] >= 2)
            {
                re = false;
                break;
            }
            if (v[i - 1] < v[i])
            {
                int cnt = 0;
                int pivot = v[i - 1];
                for (int j = i - 1; j >= 0; j--)
                {
                    if (!runway[j] && pivot == v[j])
                        cnt++;
                    else
                        break;
                }
                if (cnt >= len)
                {
                    for (int j = 0; j < len; j++)
                    {
                        runway[i - 1 - j] = true;
                    }
                }
                else
                {
                    re = false;
                    break;
                }
            }
            else if (v[i - 1] > v[i])
            {
                int cnt = 0;
                int pivot = v[i];
                for (int j = i; j < v.size(); j++)
                {
                    if (!runway[j] && pivot == v[j])
                        cnt++;
                    else
                        break;
                }
                if (cnt >= len)
                {
                    for (int j = 0; j < len; j++)
                    {
                        runway[i + j] = true;
                    }
                }
                else
                {
                    re = false;
                    break;
                }
            }
        }
    }
    return re;
}
int main()
{
    int N, L, answer = 0;

    scanf("%d %d", &N, &L);
    arr.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < N; j++)
            tmp.push_back(arr[i][j]);

        if (isRoad(tmp, L))
            answer++;

        tmp.clear();
        for (int j = 0; j < N; j++)
            tmp.push_back(arr[j][i]);

        if (isRoad(tmp, L))
            answer++;
    }

    printf("%d\n", answer);
    return 0;
}