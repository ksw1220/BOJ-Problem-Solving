#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;
vector<vector<int>> isExist;
int N, M;

bool isEqual(const vector<int> &A, const vector<int> &B)
{
    if (A.size() != B.size())
        return false;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] != B[i])
            return false;
    }
    return true;
}

void Combination(int idx, vector<int> &answer)
{
    answer.push_back(numbers[idx]);
    if (answer.size() == M)
    {
        bool chk = false;
        for (int i = 0; i < isExist.size(); i++)
        {
            if (isEqual(isExist[i], answer))
            {
                chk = true;
                break;
            }
        }
        if (!chk)
        {
            isExist.push_back(answer);
            for (int i = 0; i < M; i++)
            {
                printf("%d ", answer[i]);
            }
            printf("\n");
        }
    }
    else
    {
        for (int i = idx + 1; i < N; i++)
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
        if (i == 0 || numbers[i - 1] != numbers[i])
        {
            Combination(i, tmp);
        }
    }
    return 0;
}