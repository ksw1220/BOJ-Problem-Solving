#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> JEWEL;
vector<JEWEL> jewels;
vector<int> bags;

priority_queue<int> pq;

void solution(long long &answer)
{
    int index = 0;
    for (int i = 0; i < bags.size(); i++)
    {
        while (index < jewels.size() && jewels[index].first <= bags[i])
        {
            pq.push(jewels[index++].second);
        }
        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }
}

int main()
{

    int N, K;
    int M, V, C;
    long long answer = 0;
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &M, &V);
        jewels.push_back({M, V});
    }

    for (int i = 0; i < K; i++)
    {
        scanf("%d", &C);
        bags.push_back(C);
    }

    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());

    solution(answer);

    printf("%lld\n", answer);
    return 0;
}