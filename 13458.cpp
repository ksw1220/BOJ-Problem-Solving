#include <stdio.h>
#include <vector>

using namespace std;

vector<long long> rooms;
int main()
{
    long long N, main, sub;
    long long answer = 0;
    scanf("%lld", &N);
    rooms.assign(N, 0);

    for (long long i = 0; i < N; i++)
    {
        scanf("%lld", &rooms[i]);
    }

    scanf("%lld %lld", &main, &sub);

    for (int i = 0; i < N; i++)
    {
        int diff = rooms[i] - main;
        int tmp = 1;

        if (diff > 0)
        {
            tmp += (diff % sub) ? (diff / sub) + 1 : (diff / sub);
        }

        answer += tmp;
    }

    printf("%lld\n", answer);
    return 0;
}