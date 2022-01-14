#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 1000000001
using namespace std;

class SegmentTree
{
public:
    typedef pair<int, int> dtype;
    vector<dtype> tree;
    int s;
    int answer = 0;
    SegmentTree(int n)
    {
        for (s = 1; s <= n; s *= 2)
        {
        }
        tree.resize(s * 2);
        for (int i = 0; i < s * 2; i++)
        {
            tree[i] = {INF, 0};
        }
    }

    void insert(vector<dtype> &d)
    {
        for (int i = s; i < s + d.size(); i++)
        {
            tree[i] = d[i - s];
        }
        for (int i = s - 1; i >= 0; i--)
        {
            tree[i] = tree[i * 2].first < tree[i * 2 + 1].first ? tree[i * 2] : tree[i * 2 + 1];
        }
    }

    dtype getMin(int Left, int Right)
    {
        int l = Left + s - 1, r = Right + s - 1;
        dtype rval = {INF, 0};
        while (l <= r)
        {
            if (l % 2 == 0)
            {
                l /= 2;
            }
            else
            {
                rval = rval.first < tree[l].first ? rval : tree[l];
                l = l / 2 + 1;
            }
            if (r % 2 == 1)
            {
                r /= 2;
            }
            else
            {
                rval = rval.first < tree[r].first ? rval : tree[r];
                r = r / 2 - 1;
            }
        }
        return rval;
    }

    void solution(int Left, int Right)
    {
        if (Left > Right)
        {
            return;
        }
        dtype val = getMin(Left, Right);
        answer = max(answer, val.first * (Right - Left + 1));

        solution(Left, val.second - 1);
        solution(val.second + 1, Right);
    }
};
vector<pair<int, int>> arr;

int main()
{
    int N;

    scanf("%d", &N);
    arr.assign(N, {0, 0});
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i].first);
        arr[i].second = i + 1;
    }

    SegmentTree t(N);
    t.insert(arr);
    t.solution(1, N);

    printf("%d\n", t.answer);

    return 0;
}