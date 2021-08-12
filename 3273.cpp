#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{
    int N, X;
    scanf("%d", &N);

    int left = 0, right = N - 1, answer = 0;

    v.assign(N, 0);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &v[i]);
    }

    scanf("%d", &X);

    sort(v.begin(), v.end());

    while (left < right)
    {
        int sum = v[left] + v[right];
        if (sum == X)
        {
            left++;
            right--;
            answer++;
        }
        else if (sum > X)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    printf("%d\n", answer);
    return 0;
}