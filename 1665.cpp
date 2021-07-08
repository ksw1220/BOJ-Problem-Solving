#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int N, x;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    scanf("%d", &N);

    while (N--)
    {
        scanf("%d", &x);
        maxHeap.size() == minHeap.size() ? maxHeap.push(x) : minHeap.push(x);

        while (!maxHeap.empty() && !minHeap.empty() && minHeap.top() < maxHeap.top())
        {
            int maxTmp = maxHeap.top();
            int minTmp = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(minTmp);
            minHeap.push(maxTmp);
        }

        printf("%d\n", maxHeap.top());
    }

    return 0;
}