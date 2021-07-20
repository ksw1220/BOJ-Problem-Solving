#include <stdio.h>
#include <queue>
#include <vector>
#define INF 987654321
#define MAX 100001
using namespace std;

vector<int> dist;
void solution(int N, int K, int &answer, int &cnt)
{
    queue<int> pos;
    pos.push(N);
    dist[N] = 0;

    while (!pos.empty())
    {
        int now = pos.front();
        pos.pop();

        if (now == K)
        {
            if (answer > dist[now])
            {
                answer = dist[now];
                cnt = 1;
            }
            else if (answer == dist[now])
            {
                cnt++;
            }
        }
        if (now < 100000 && dist[now + 1] >= dist[now] + 1)
        {
            dist[now + 1] = dist[now] + 1;
            pos.push(now + 1);
        }
        if (now > 0 && dist[now - 1] >= dist[now] + 1)
        {
            dist[now - 1] = dist[now] + 1;
            pos.push(now - 1);
        }
        if (now * 2 <= 100000 && dist[now * 2] >= dist[now] + 1)
        {
            dist[now * 2] = dist[now] + 1;
            pos.push(now * 2);
        }
    }
}
int main()
{
    int N, K, answer = INF, cnt = 0;
    scanf("%d %d", &N, &K);
    dist.assign(MAX, INF);

    solution(N, K, answer, cnt);

    printf("%d\n%d\n", answer, cnt);
    return 0;
}