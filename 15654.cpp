#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numbers;
vector<bool> visited;
int N, M;
void Combination(int idx, vector<int> &acc)
{
    acc.push_back(idx);
    visited[idx] = true;
    if (acc.size() == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", numbers[acc[i]]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                Combination(i, acc);
            }
        }
    }
    acc.pop_back();
    visited[idx] = false;
}
int main()
{
    vector<int> tmp;
    scanf("%d %d", &N, &M);

    numbers.assign(N, 0);
    visited.assign(N, false);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &numbers[i]);
    }
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < N; i++)
    {
        Combination(i, tmp);
    }
    return 0;
}