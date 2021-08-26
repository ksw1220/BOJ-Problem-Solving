#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<vector<int>> dp;
string s;

int palindrome(int left, int right)
{
    int re = INF;

    if (dp[left][right])
    {
        re = dp[left][right];
    }
    else if (left == right)
    {
        re = 1;
    }
    else if (left + 1 == right)
    {
        re = s[left] == s[right] ? 1 : 2;
    }
    else
    {
        if (s[left] == s[right])
        {
            re = palindrome(left + 1, right - 1);
            re = re == 1 ? re : re + 2;
        }
        if (re != 1)
        {
            for (int i = left; i < right; i++)
            {
                re = min(re, palindrome(left, i) + palindrome(i + 1, right));
            }
        }
    }

    return dp[left][right] = re;
}

int main()
{
    cin >> s;

    dp.assign(s.length(), vector<int>(s.length(), 0));

    printf("%d\n", palindrome(0, s.length() - 1));
    return 0;
}