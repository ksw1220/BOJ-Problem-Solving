#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    string s;
    vector<string> v;

    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        v.push_back(s.substr(i, s.length()));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}