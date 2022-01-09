#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class SegmentTree
{
public:
    typedef int dtype;
    vector<dtype> tree;
    int s;

    SegmentTree(int n)
    {
        for (s = 1; s <= n; s *= 2)
        {
        }
        tree.resize(s * 2);
        for (int i = 0; i < s * 2; i++)
        {
            tree[i] = 0;
        }
    }

    dtype getSum(int Left, int Right)
    {
        int l = Left + s - 1, r = Right + s - 1;
        dtype rval = 0;
        while (l <= r)
        {
            if (l % 2 == 0)
            {
                l /= 2;
            }
            else
            {
                rval += tree[l];
                l = l / 2 + 1;
            }
            if (r % 2 == 1)
            {
                r /= 2;
            }
            else
            {
                rval += tree[r];
                r = r / 2 - 1;
            }
        }
        return rval;
    }

    void update(int index, dtype val)
    {
        int idx = index + s - 1;
        tree[idx] = val;
        while (idx)
        {
            idx /= 2;
            tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
        }
    }
};
vector<int> stats, sorted;

int main()
{
    int N;
    scanf("%d", &N);
    stats.assign(N, 0);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &stats[i]);
    }

    SegmentTree t(N);

    sorted = stats;
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < N; i++)
    {
        int idx = lower_bound(sorted.begin(), sorted.end(), stats[i]) - sorted.begin() + 1;
        t.update(idx, 1);
        int forward = t.getSum(1, idx - 1);
        printf("%d\n", i + 1 - forward);
    }
    return 0;
}