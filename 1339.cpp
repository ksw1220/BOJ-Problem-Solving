#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
vector<char> chars;
vector<int> charToNum;
vector<bool> visited(10, false);
map<char, int> weight;

int answer = 0;
bool isExist(char x)
{
    for (int i = 0; i < chars.size(); i++)
    {
        if (chars[i] == x)
        {
            return true;
        }
    }
    return false;
}
void dfs(int cnt)
{
    if (cnt == chars.size())
    {
        int val = 0;
        for (int i = 0; i < chars.size(); i++)
        {
            val += charToNum[i] * weight[chars[i]];
        }
        answer = answer > val ? answer : val;
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (visited[i])
            continue;
        charToNum[cnt] = i;
        visited[i] = true;
        dfs(cnt + 1);
        visited[i] = false;
    }
}
int main()
{
    int N;
    cin >> N;

    string word;
    for (int i = 0; i < N; i++)
    {
        cin >> word;
        int w = 1;
        for (int j = word.length() - 1; j >= 0; j--)
        {
            if (!isExist(word[j]))
            {
                chars.push_back(word[j]);
                weight[word[j]] = w;
            }
            else
            {
                weight[word[j]] += w;
            }
            w *= 10;
        }
    }

    charToNum.assign(chars.size(), 0);

    dfs(0);
    cout << answer << endl;
    return 0;
}