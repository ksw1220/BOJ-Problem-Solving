#include <stdio.h>
#include <deque>

using namespace std;
deque<int> dq;
int find_target(int target)
{
    int re;
    for (int i = 0; i < dq.size(); i++)
    {
        if (dq[i] == target)
            re=i;
    }
    return re;
}

int pop_target(int idx)
{
    int tmp, time, re;
    if (idx <= dq.size() - idx)
    {
        re = time = idx;
        while (time--)
        {
            tmp = dq.front();
            dq.pop_front();
            dq.push_back(tmp);
        }
    }
    else
    {
        re = time = dq.size() - idx;
        while (time--)
        {
            tmp = dq.back();
            dq.pop_back();
            dq.push_front(tmp);
        }
    }
    dq.pop_front();
    return re;
}

int main()
{
    int N, M, target, answer = 0;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        dq.push_back(i + 1);
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &target);
        int idx = find_target(target);
        answer += pop_target(idx);
    }
    printf("%d\n", answer);
    return 0;
}