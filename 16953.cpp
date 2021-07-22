#include <stdio.h>
#include <queue>

using namespace std;

queue<pair<long long, int>> numbers;
int main()
{
    long long A, B;
    int answer = -1;
    scanf("%lld %lld", &A, &B);

    numbers.push({A, 1});

    while (!numbers.empty())
    {
        long long now = numbers.front().first;
        int cnt = numbers.front().second;
        numbers.pop();

        if (now == B)
        {
            answer = cnt;
            break;
        }

        if (now * 2 <= B)
        {
            numbers.push({now * 2, cnt + 1});
        }
        if (now * 10 + 1 <= B)
        {
            numbers.push({now * 10 + 1, cnt + 1});
        }
    }
    printf("%d\n", answer);
    return 0;
}