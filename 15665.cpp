#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> numbers;
vector<vector<int>> isExist;
set<int> numberSet;
int N, M;

void Combination(int idx, vector<int> &answer)
{
    answer.push_back(numbers[idx]);
    if (answer.size() == M)
    {

        for (int i = 0; i < M; i++)
        {
            printf("%d ", answer[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 0; i < numbers.size(); i++)
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

    for (int i = 0; i < N; i++)
    {
        int input;
        scanf("%d", &input);
        numberSet.insert(input);
    }

    set<int>::iterator it;
    for (it = numberSet.begin(); it != numberSet.end(); it++)
    {
        numbers.push_back(*it);
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.size(); i++)
    {
        if (i == 0 || numbers[i - 1] != numbers[i])
        {
            Combination(i, tmp);
        }
    }
    return 0;
}