#include <stdio.h>
#include <vector>
#include <algorithm>

#define MIN 0
#define MAX 1000000000
using namespace std;

vector<int> loc;

bool isPossible(int interval, int router)
{
    int idx = 0, cnt = 1;
    for (int i = 1; i < loc.size(); i++)
    {
        if (loc[i] - loc[idx] >= interval)
        {
            idx = i;
            cnt++;
        }
    }
    return router <= cnt;
}

int main()
{
    int N, C;
    int answer = 0;
    scanf("%d %d", &N, &C);

    loc.assign(N, 0);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &loc[i]);
    }

    sort(loc.begin(), loc.end());

    int left = MIN, right = MAX;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (isPossible(mid, C))
        {
            left = mid + 1;
            answer = max(answer, mid);
        }
        else
        {
            right = mid - 1;
        }
    }

    printf("%d\n", answer);
    return 0;
}