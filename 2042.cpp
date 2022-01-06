#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr;

long long sum(long long a, long long b)
{
    return a + b;
}
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
        for (int i = 1; i <= s; i++)
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
            tree[i] = sum(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    dtype getSum(int Left, int Right)
    {
        int l = Left + s - 1, r = Right + s - 1;
        dtype rval = 0;
        while (l <= r)
        {
            // l이 왼쪽 노드일 때
            if (l % 2 == 0)
            {
                l /= 2;
            }
            else
            {
                rval = sum(rval, tree[l]);
                l = (l / 2) + 1;
            }
            if (r % 2 == 1)
            {
                r /= 2;
            }
            else
            {
                rval = sum(rval, tree[r]);
                r = (r / 2) - 1;
            }
        }
        return rval;
    }

    void update(int index, long long val)
    {
        int idx = index + s - 1;
        tree[idx] = val;
        while (idx)
        {
            idx /= 2;
            tree[idx] = sum(tree[idx * 2], tree[idx * 2 + 1]);
        }
    }
};
int main()
{
    int N, M, K;
    int a, b;
    long long c;
    scanf("%d %d %d", &N, &M, &K);
    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
    }

    SegmentTree t(N);
    t.insert(arr);

    for (int iter = 0; iter < M + K; iter++)
    {
        scanf("%d %d %lld", &a, &b, &c);
        if (a == 1)
        {
            t.update(b, c);
        }
        else if (a == 2)
        {
            printf("%lld\n", t.getSum(b, c));
        }
    }
    return 0;
}