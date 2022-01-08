#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int N, K;
vector<int> arr;
vector<bool> visited;
set<string> integers;

void comb(int cnt, string intString)
{
    if (cnt == K)
    {
        integers.insert(intString);
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            comb(cnt + 1, intString + to_string(arr[i]));
            visited[i] = false;
        }
    }
}
int main()
{
    cin >> N >> K;
    arr.assign(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    visited.assign(N, false);
    comb(0, "");

    cout << integers.size() << endl;
    return 0;
}