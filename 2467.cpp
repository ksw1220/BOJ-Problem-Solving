#include <stdio.h>
#include <vector>

#define MAX 2000000000

using namespace std;
vector<int> arr;

int ansLeft, ansRight, opt = MAX;
int isOptimal(int left, int right)
{
    int re;
    int now = re = arr[left] + arr[right];
    if (now < 0)
        now *= -1;
    if (opt > now)
    {
        opt = now;
        ansLeft = left;
        ansRight = right;
    }
    return re;
}
int main()
{
    int N;
    scanf("%d", &N);
    arr.assign(N, 0);
    int left = 0, right = N - 1;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (left < right)
    {
        int tmp = isOptimal(left, right);
        if (tmp == 0)
        {
            break;
        }
        else if (tmp < 0)
            left++;

        else
            right--;
    }

    printf("%d %d\n", arr[ansLeft], arr[ansRight]);
    return 0;
}