#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<bool>> chk;
int answer = 0, K;
void dfs(string s, int cnt)
{
    if (cnt == K)
    {
        int now = stoi(s);
        answer = answer > now ? answer : now;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j < s.length(); j++)
        {
            string tmp = s;
            tmp[i] = s[j];
            tmp[j] = s[i];
            if (tmp[0] == '0')
                continue;
            int tmp_num = stoi(tmp);
            if (!chk[cnt + 1][tmp_num])
            {
                chk[cnt + 1][tmp_num] = true;
                dfs(tmp, cnt + 1);
            }
        }
    }
}
int main()
{
    string N;
    cin >> N;
    cin >> K;

    chk.assign(K + 1, vector<bool>(1000001, false));

    chk[0][stoi(N)] = true;
    dfs(N, 0);
    if (answer == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << answer << endl;
    }
    return 0;
}