#include <stdio.h>
#include <vector>
#define MOD 1000000007
using namespace std;

typedef long long dtype;

class SegmentTree
{
public:
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

    void insert(vector<dtype> &d)
    {
        for (int i = s; i < s + d.size(); i++)
        {
            tree[i] = d[i - s];
        }
        for (int i = s - 1; i > 0; i--)
        {
            tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % MOD;
        }
    }

    dtype getMulti(int Left, int Right)
    {
        int l = Left + s - 1, r = Right + s - 1;
        dtype rval = 1;
        while (l <= r)
        {
            if (l % 2 == 0)
            {
                l /= 2;
            }
            else
            {
                rval = (rval * tree[l]) % MOD;
                l = l / 2 + 1;
            }
            if (r % 2 == 1)
            {
                r /= 2;
            }
            else
            {
                rval = (rval * tree[r]) % MOD;
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
            tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % MOD;
        }
    }
};
vector<dtype> arr;
int main()
{
    int N, M, K, a, b, c;
    scanf("%d %d %d", &N, &M, &K);

    arr.assign(N, 0);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
    }
    SegmentTree t(N);
    t.insert(arr);

    for (int i = 0; i < M + K; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1)
        {
            t.update(b, (dtype)c);
        }
        else if (a == 2)
        {
            printf("%lld\n", t.getMulti(b, c));
        }
    }
    return 0;
}