#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct st
{
    int x, idx;
};
bool operator<(st a, st b)
{
    return a.x > b.x;
}
priority_queue<st> pq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int L, N, input;
    cin >> N >> L;

    for (int i = 0; i < L; i++)
    {
        cin >> input;
        pq.push({input, i});
        cout << pq.top().x << " ";
    }

    for (int i = L; i < N; i++)
    {
        cin >> input;
        pq.push({input, i});
        while (pq.top().idx < i - L + 1)
        {
            pq.pop();
        }
        cout << pq.top().x << " ";
    }
    return 0;
}