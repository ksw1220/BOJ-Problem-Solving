#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;
int N, M;

void Combination(int idx, vector<int> &answer)
{

    answer.push_back(idx);
    if (answer.size() == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", numbers[answer[i]]);
        }
        printf("\n");
    }
    else
    {
        for (int i = idx; i < N; i++)
        {
            Combination(i, answer);
        }
    }
    answer.pop_back();
}
int main()
{
    vector<int> tmp;
    scanf("%d %d", &N, &M);

    numbers.assign(N, 0);

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