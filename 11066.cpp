#include <stdio.h>
#include <vector>
#define INF 987654321
using namespace std;

typedef struct MERGED
{
    int size, acc;
} MERGED;

vector<vector<MERGED>> dp;
vector<int> files;

MERGED merge(int left, int right)
{
    MERGED re;
    re.acc = INF;

    if (dp[left][right].acc != INF)
    {
        re = dp[left][right];
    }
    else if (left == right)
    {
        re = {files[left], 0};
    }
    else
    {
        for (int i = left; i < right; i++)
        {
            MERGED L = merge(left, i);
            MERGED R = merge(i + 1, right);

            MERGED tmp;
            tmp.size = L.size + R.size;
            tmp.acc = L.acc + R.acc + tmp.size;

            if (re.acc > tmp.acc)
            {
                re = tmp;
            }
        }
    }

    return dp[left][right] = re;
}

int main()
{
    int T, K;
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &K);
        files.assign(K, 0);
        dp.assign(K, vector<MERGED>(K, {INF, INF}));

        for (int i = 0; i < K; i++)
        {
            scanf("%d", &files[i]);
        }

        printf("%d\n", merge(0, K - 1).acc);
    }

    return 0;
}