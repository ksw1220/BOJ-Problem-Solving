#include <iostream>
#include <vector>

using namespace std;

vector<long long> trees;
long long get(long long height)
{
    long long re = 0;
    for (int i = 0; i < trees.size(); i++)
    {
        if (trees[i] > height)
        {
            re += trees[i] - height;
        }
    }

    return re;
}
int main()
{
    int N;
    long long M;
    long long l, r, answer = 0;
    cin >> N >> M;

    trees.assign(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> trees[i];
    }

    l = 0;
    r = 2000000000;

    while (l <= r)
    {
        long long mid = (l + r) / 2;
        long long tmp = get(mid);
        if (tmp >= M)
        {
            l = mid + 1;
            answer = answer > mid ? answer : mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << answer << endl;
    return 0;
}