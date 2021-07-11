#include <stdio.h>
#include <algorithm>

using namespace std;
int arr[100001][3];
int maxDp[2][3];
int minDp[2][3];
int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }

    maxDp[0][0] = minDp[0][0] = arr[0][0];
    maxDp[0][1] = minDp[0][1] = arr[0][1];
    maxDp[0][2] = minDp[0][2] = arr[0][2];

    for (int i = 1; i < N; i++)
    {
        maxDp[i % 2][0] = max(maxDp[(i - 1) % 2][0], maxDp[(i - 1) % 2][1]) + arr[i][0];
        maxDp[i % 2][1] = max({maxDp[(i - 1) % 2][0], maxDp[(i - 1) % 2][1], maxDp[(i - 1) % 2][2]}) + arr[i][1];
        maxDp[i % 2][2] = max(maxDp[(i - 1) % 2][2], maxDp[(i - 1) % 2][1]) + arr[i][2];

        minDp[i % 2][0] = min(minDp[(i - 1) % 2][0], minDp[(i - 1) % 2][1]) + arr[i][0];
        minDp[i % 2][1] = min({minDp[(i - 1) % 2][0], minDp[(i - 1) % 2][1], minDp[(i - 1) % 2][2]}) + arr[i][1];
        minDp[i % 2][2] = min(minDp[(i - 1) % 2][2], minDp[(i - 1) % 2][1]) + arr[i][2];
    }
    printf("%d ", max({maxDp[(N - 1) % 2][0], maxDp[(N - 1) % 2][1], maxDp[(N - 1) % 2][2]}));
    printf("%d\n", min({minDp[(N - 1) % 2][0], minDp[(N - 1) % 2][1], minDp[(N - 1) % 2][2]}));
    return 0;
}
