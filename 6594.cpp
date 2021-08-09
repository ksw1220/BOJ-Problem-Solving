#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

stack<pair<long long, long long>> st;
int main()
{
    long long N, x;
    while (1)
    {
        long long answer = 0;
        scanf("%lld", &N);
        if (N == 0)
            break;

        for (long long i = 0; i < N; i++)
        {
            scanf("%lld", &x);
            long long idx = i;
            while (!st.empty() && st.top().first >= x)
            {
                answer = max(answer, st.top().first * (i - st.top().second));
                idx = st.top().second;
                st.pop();
            }
            st.push({x, idx});
        }
        while (!st.empty())
        {
            answer = max(answer, st.top().first * (N - st.top().second));
            st.pop();
        }
        printf("%lld\n", answer);
    }
    return 0;
}