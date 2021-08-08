#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> acc;
int N, S;

bool findMax(int size)
{
    bool re = false;
    for (int i = 0; i + size <= N; i++)
    {
        if (acc[i + size] - acc[i] >= S)
        {
            re = true;
            break;
        }
    }
    return re;
}
int main()
{
    int x;
    int left, right;
    int answer = -1;
    scanf("%d %d", &N, &S);
    acc.assign(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &x);
        acc[i] = acc[i - 1] + x;
    }

    left = 1, right = N;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (findMax(mid))
        {
            right = mid - 1;
            answer = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (answer == -1)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", answer);
    }
    return 0;
}