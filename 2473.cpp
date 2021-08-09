#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

long long answer = 10000000000;
int ansLeft, ansMid, ansRight;
vector<long long> v;
void BinarySearch(int start, int end)
{
    int left = start + 1;
    int right = end - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long sum = v[start] + v[end] + v[mid];

        if (sum > 0)
        {
            right = mid - 1;
        }
        else if (sum < 0)
        {
            left = mid + 1;
        }
        else
        {
        }
        if (abs(sum) < answer)
        {
            answer = abs(sum);
            ansLeft = start;
            ansMid = mid;
            ansRight = end;
        }
        if (answer == 0)
        {
            return;
        }
    }
}
int main()
{
    int N;
    scanf("%d", &N);

    v.assign(N, 0);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &v[i]);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 2; j < N; j++)
        {
            BinarySearch(i, j);
        }
    }

    printf("%lld %lld %lld\n", v[ansLeft], v[ansMid], v[ansRight]);
    return 0;
}