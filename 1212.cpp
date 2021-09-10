#include <iostream>
#include <string>

using namespace std;

string octToDec(char x)
{
    int oct = x - '0';
    string dec = "";
    while (oct)
    {
        string tmp = oct % 2 ? "1" : "0";
        dec = tmp + dec;
        oct /= 2;
    }

    while (dec.length() < 3)
    {
        dec = "0" + dec;
    }
    return dec;
}
int main()
{
    string s;
    cin >> s;

    string tmp=octToDec(s[0]);
   
    cout<<stoi(tmp);
    for (int i = 1; i < s.length(); i++)
    {
        tmp = octToDec(s[i]);
        cout<<tmp;
    }
    return 0;
}