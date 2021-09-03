#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<bool> visited;
bool dfs(int start, int now)
{
    bool re = false;
    visited[now] = true;
    if (start == now)
    {
        re = true;
    }
    else if (!visited[arr[now]])
    {
        re = dfs(start, arr[now]);
    }

    return re;
}
int main()
{
    int N;
    cin >> N;
    vector<int> answer;

    arr.assign(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++)
    {
        visited.assign(N + 1, false);
        if (dfs(i, arr[i]))
        {
            answer.push_back(i);
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << endl;

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
    return 0;
}