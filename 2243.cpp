#include <iostream>
#include <vector>
#include <stdio.h>
#define SIZE 1000000
using namespace std;

class SegmentTree
{
public:
    typedef int dtype;
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

    int getCandy(int priority)
    {
        int idx = 1, acc = 0, reIdx;
        while (idx < s)
        {
            if (tree[idx * 2] + acc < priority)
            {
                acc += tree[idx * 2];
                idx = idx * 2 + 1;
            }
            else
            {
                idx = idx * 2;
            }
        }
        reIdx = idx;
        tree[idx] -= 1;
        while (idx)
        {
            idx /= 2;
            tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
        }
        return reIdx - s + 1;
    }

    void add(int index, dtype val)
    {
        int idx = index + s - 1;
        tree[idx] += val;
        while (idx)
        {
            idx /= 2;
            tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
        }
    }
};
int main()
{
    int N;
    int a, b, c;
    cin >> N;
    SegmentTree t(SIZE);
    while (N--)
    {
        scanf("%d %d", &a, &b);
        if (a == 1)
        {
            printf("%d\n", t.getCandy(b));
        }
        else if (a == 2)
        {
            scanf("%d", &c);
            t.add(b, c);
        }
    }
    return 0;
}