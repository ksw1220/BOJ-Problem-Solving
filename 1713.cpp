#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct candidate
{
    int number, recommend, time;
} C;

bool myFunction(candidate a, candidate b)
{
    if (a.recommend != b.recommend)
    {
        return a.recommend < b.recommend;
    }
    return a.time < b.time;
}
bool myFunction2(candidate a, candidate b)
{
    return a.number < b.number;
}
vector<candidate> candidates;
int main()
{
    int N, M, number;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int idx = -1;
        cin >> number;
        for (int j = 0; j < candidates.size(); j++)
        {
            if (candidates[j].number == number)
            {
                idx = j;
                break;
            }
        }
        if (idx != -1)
        {
            candidates[idx].recommend++;
        }
        else
        {
            if (candidates.size() < N)
            {
                candidates.push_back({number, 1, i});
            }
            else
            {
                candidates[0] = {number, 1, i};
            }
        }
        sort(candidates.begin(), candidates.end(), myFunction);
    }
    sort(candidates.begin(), candidates.end(), myFunction2);

    for (int i = 0; i < candidates.size(); i++)
    {
        cout << candidates[i].number << " ";
    }
    return 0;
}