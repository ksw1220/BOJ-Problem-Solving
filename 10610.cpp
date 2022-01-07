#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    int sum = 0;
    cin >> s;
    sort(s.begin(), s.end());

    if (s[0] - '0' != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < s.length(); i++)
    {
        sum += (s[i] - '0');
    }
    if (sum % 3 == 0)
    {
        for (int i = s.length() - 1; i >= 0; i--)
        {
            cout << s[i];
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}