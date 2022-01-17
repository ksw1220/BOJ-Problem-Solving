#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    string s, buffer;
    cin >> T;
    cin >> buffer;
    while (T--)
    {
        getline(cin, s);
        s += " ";
        int start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                for (int j = i - 1; j >= start; j--)
                {
                    cout << s[j];
                }
                cout << " ";
                start = i + 1;
            }
        }
        cout<<endl;
    }
    return 0;
}