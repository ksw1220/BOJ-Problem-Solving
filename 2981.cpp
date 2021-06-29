#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

vector<int> answers;
int main()
{
    int N, answer;
    int arr[101];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr,arr+N);
    answer = arr[1] - arr[0];
    for (int i = 1; i < N - 1; i++)
    {
        answer = gcd(answer, arr[i + 1] - arr[i]);
    }

    for (int i = 1; i * i <= answer; i++)
    {
        if (answer % i == 0)
        {
            answers.push_back(i);
            if (i * i != answer)
                answers.push_back(answer / i);
        }
        sort(answers.begin(), answers.end());
    }
    for (int i = 0; i < answers.size(); i++)
    {
        if(answers[i]==1)continue;
        printf("%d ", answers[i]);
    }
    return 0;
}