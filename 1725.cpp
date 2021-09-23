#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define INF 987654321
using namespace std;

class SegmentTree
{
public:
    typedef pair<int, int> dtype;

    vector<dtype> tree;

    int s;

    SegmentTree(int N)
    {
        for (s = 1; s < N; s *= 2)
        {
        }
        tree.resize(s * 2);
        for (int i = 1; i < s * 2; i++)
            tree[i] = {-1, INF};
    }

    void insert(vector<dtype> &d)
    {
        for (int i = s; i < s + d.size(); i++)
            tree[i] = d[i - s];
        for (int i = s - 1; i >= 1; i--)
        {
            tree[i] = tree[i * 2].second < tree[i * 2 + 1].second ? tree[i * 2] : tree[i * 2 + 1];
        }
    }

    dtype getMin(int Left, int Right)
    {
        int l = Left + s - 1, r = Right + s - 1;
        dtype rval = {-1, INF};
        while (l <= r)
        {
            if (l % 2 == 0)
                l /= 2;
            else
            {
                rval = rval.second < tree[l].second ? rval : tree[l];
                l = (l / 2) + 1;
            }
            if (r % 2 == 1)
                r /= 2;
            else
            {
                rval = rval.second < tree[r].second ? rval : tree[r];
                r = (r / 2) - 1;
            }
        }
        return rval;
    }
};

int solution(SegmentTree *T, int left, int right)
{
    if (left > right)
    {
        return 0;
    }
    pair<int, int> tmp = T->getMin(left, right);
    int re = tmp.second * (right - left + 1);
    int idx = tmp.first + 1;
    if (idx != left)
        re = max(re, solution(T, left, idx - 1));
    if (idx != right)
        re = max(re, solution(T, idx + 1, right));

    return re;
}
int main()
{
    int N, m;

    cin >> N;

    SegmentTree t(N);

    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++)
    {
        v[i].first = i;
        cin >> v[i].second;
    }

    t.insert(v);
    cout << solution(&t, 1, N);
}
