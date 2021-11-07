#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, K, answer = 0, bit = 0;
vector<string> words;
int getBit(string s)
{
    int bit = 0;
    for (int i = 4; i < s.length() - 4; i++)
    {
        bit |= 1 << (s[i] - 'a');
    }
    return bit;
}

void init()
{
    string antic = "antic";
    for (int i = 0; i < antic.length(); i++)
    {
        bit |= 1 << (antic[i] - 'a');
    }
}
void dfs(int nowBit, int cnt, int now)
{
    if (cnt == K)
    {
        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            int comparedBit = getBit(words[i]);
            if ((nowBit | comparedBit) == nowBit)
                count++;
        }
        answer = answer > count ? answer : count;
        return;
    }
    for (int i = now + 1; i < 26; i++)
    {
        if ((nowBit | (1 << i)) == nowBit)
            continue;
        dfs(nowBit | (1 << i), cnt + 1, i);
    }
}
int main()
{
    cin >> N >> K;
    words.assign(N, "");

    init();
    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
    }

    dfs(bit, 5, 0);
    cout << answer << endl;

    return 0;
}