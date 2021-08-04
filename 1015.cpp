#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> arr;
vector<int> answer;
int main()
{
    int N, x;
    scanf("%d", &N);
    answer.assign(N, 0);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        arr.push_back({x, i});
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++)
    {
        answer[arr[i].second] = i;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", answer[i]);
    }
    return 0;
}