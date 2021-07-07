#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int T, N, val;
    char op, buffer;
    scanf("%d", &T);
    while (T--)
    {
        priority_queue<pair<int, int> > maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minHeap;

        int idx = 0;
        scanf("%d", &N);
        vector<bool> check(N, false);
        for (int i = 0; i < N; i++)
        {
            scanf("%c", &buffer);
            scanf("%c %d", &op, &val);
            if (op == 'I')
            {
                maxHeap.push({val, idx});
                minHeap.push({val, idx});
                check[idx++] = true;
            }
            else
            {
                if (val == 1)
                {
                    while (!maxHeap.empty() && !check[maxHeap.top().second])
                    {
                        maxHeap.pop();
                    }
                    if (maxHeap.empty())
                        continue;
                    check[maxHeap.top().second] = false;
                    maxHeap.pop();
                }
                else
                {
                    while (!minHeap.empty() && !check[minHeap.top().second])
                    {
                        minHeap.pop();
                    }
                    if (minHeap.empty())
                        continue;
                    check[minHeap.top().second] = false;
                    minHeap.pop();
                }
            }
        }
        while (!maxHeap.empty() && !check[maxHeap.top().second])
        {
            maxHeap.pop();
        }
        while (!minHeap.empty() && !check[minHeap.top().second])
        {
            minHeap.pop();
        }
        if (maxHeap.empty() && minHeap.empty())
        {
            printf("EMPTY\n");
        }
        else
        {
            printf("%d %d\n", maxHeap.top().first, minHeap.top().first);
        }
    }
    return 0;
}