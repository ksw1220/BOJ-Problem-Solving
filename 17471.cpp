#include <iostream>
#include <vector>
#include <map>
#define INF 987654321
using namespace std;

vector<int> cities;
vector<vector<int>> adj;
vector<int> districtA, districtB;
vector<bool> visited;

int sum = 0, answer = INF;

bool isInDistrict(int target, vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == target)
        {
            return true;
        }
    }

    return false;
}
void dfs(int now, int &cnt, vector<int> &district)
{
    visited[now] = true;
    cnt++;

    for (int i = 0; i < adj[now].size(); i++)
    {
        int next = adj[now][i];
        if (!visited[next] && isInDistrict(next, district))
        {
            dfs(next, cnt, district);
        }
    }
}
bool isPossible()
{
    visited.assign(cities.size(), false);
    int start = 1, cnt = 0;

    dfs(start, cnt, districtA);
    if (cnt != districtA.size())
    {
        return false;
    }

    visited.assign(cities.size(), false);
    start = districtB[0], cnt = 0;

    dfs(start, cnt, districtB);
    if (cnt != districtB.size())
    {
        return false;
    }

    return true;
}
void makeDistrict(int now, int cnt)
{
    if (cnt == cities.size() - 1 && !districtB.empty() && isPossible())
    {
        int A = 0, B;
        for (int i = 0; i < districtA.size(); i++)
        {
            A += cities[districtA[i]];
        }

        B = sum - A;
        int diff = A - B;
        diff = diff > 0 ? diff : diff * -1;

        answer = answer > diff ? diff : answer;
    }
    else if (now == cities.size())
    {
        return;
    }
    else
    {
        districtA.push_back(now);
        makeDistrict(now + 1, cnt + 1);
        districtA.pop_back();

        districtB.push_back(now);
        makeDistrict(now + 1, cnt + 1);
        districtB.pop_back();
    }
}
int main()
{
    int N, count, tmp;

    cin >> N;
    cities.assign(N + 1, 0);
    adj.assign(N + 1, vector<int>(0, 0));

    for (int i = 1; i <= N; i++)
    {
        cin >> cities[i];
        sum += cities[i];
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> count;
        while (count--)
        {
            cin >> tmp;
            adj[i].push_back(tmp);
        }
    }

    districtA.push_back(1);
    makeDistrict(2, 1);

    if (answer == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << answer << endl;
    }
    return 0;
}