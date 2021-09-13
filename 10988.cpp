#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s)
{
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - i - 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s;
    cin >> s;

    int answer = isPalindrome(s) ? 1 : 0;

    cout << answer << endl;
    return 0;
}