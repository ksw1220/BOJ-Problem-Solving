#include <iostream>
#include <string>
using namespace std;

void inspect(string s)
{
    int lower = 0, upper = 0, digit = 0, blank = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            lower++;
        }
        else if ('A' <= s[i] && s[i] <= 'Z')
        {
            upper++;
        }
        else if ('0' <= s[i] && s[i] <= '9')
        {
            digit++;
        }
        else if (s[i] == ' ')
        {
            blank++;
        }
    }

    cout << lower << " " << upper << " " << digit << " " << blank << endl;
}
int main()
{
    string s;
    while (getline(cin, s))
    {
        inspect(s);
    }
    return 0;
}