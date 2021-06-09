#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct mystruct
{
    int value, index;
} My;
mystruct arr[1000001];
bool myfunction(mystruct a, mystruct b)
{

    return a.value < b.value;
}
int main()
{
    int N, tmp;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &tmp);
        arr[i] = {tmp, i};
    }
    vector<int> ans(N, 0);
    sort(arr, arr + N, myfunction);

    ans[arr[0].index] = 0;
    int cnt = 0;
    for (int i = 1; i < N; i++)
    {
        if (arr[i].value == arr[i - 1].value)
        {
            ans[arr[i].index] = cnt;
        }
        else
            ans[arr[i].index] = ++cnt;
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}