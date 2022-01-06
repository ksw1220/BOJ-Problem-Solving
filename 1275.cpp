#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
vector<long long> arr;

class SegmentTree
{
public:
    typedef long long dtype;
    vector<dtype> tree;
    int s;

    SegmentTree(int n)
    {
        for (s = 1; s < n; s *= 2)
        {
        }
        tree.resize(s * 2);
        for (int i = 0; i < s * 2; i++)
        {
            tree[i] = 0;
        }
    }

    void insert(vector<dtype> &d)
    {
        for (int i = s; i < s + d.size(); i++)
        {
            tree[i] = d[i - s];
        }
        for (int i = s - 1; i >= 1; i--)
        {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
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
                l = (l / 2) + 1;
            }
            if (r % 2 == 1)
            {
                r /= 2;
            }
            else
            {
                rval += tree[r];
                r = (r / 2) - 1;
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
int main()
{
    int N, Q;
    int x, y, a;
    long long b;
    cin >> N >> Q;

    arr.resize(N);

    SegmentTree t(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
    }
    t.insert(arr);

    while (Q--)
    {
        scanf("%d %d %d %lld", &x, &y, &a, &b);
        if (x > y)
        {
            int tmp = x;
            x = y;
            y = tmp;
        }
        printf("%lld\n", t.getSum(x, y));
        t.update(a, b);
    }
    return 0;
}