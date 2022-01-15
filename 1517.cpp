#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(long long a, long long b)
{
    return a > b;
}
class SegmentTree
{
public:
    typedef long long dtype;
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

    void decrease(int index)
    {
        int idx = index + s - 1;
        tree[idx]--;
        while (idx)
        {
            idx /= 2;
            tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
        }
    }
};
vector<int> arr, sorted, v;
vector<long long> cnt;
int main()
{
    int N;
    long long answer = 0;
    scanf("%d", &N);
    arr.assign(N, 0);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    sorted = arr;
    sort(sorted.begin(), sorted.end());

    v.push_back(sorted[0]);
    cnt.push_back(1);
    for (int i = 1; i < N; i++)
    {
        if (sorted[i - 1] == sorted[i])
        {
            cnt[cnt.size() - 1]++;
        }
        else
        {
            v.push_back(sorted[i]);
            cnt.push_back(1);
        }
    }
    SegmentTree t(v.size());
    t.insert(cnt);

    for (int i = 0; i < N; i++)
    {
        int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
        answer += t.getSum(1, idx - 1);
        t.decrease(idx);
    }

    printf("%lld\n", answer);
    return 0;
}