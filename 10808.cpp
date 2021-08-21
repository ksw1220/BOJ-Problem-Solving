#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int alpha[26];
int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        alpha[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%d ",alpha[i]);
    }
    return 0;
}