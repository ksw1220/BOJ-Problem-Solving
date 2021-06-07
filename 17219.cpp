#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> info;
int main()
{
    int N, M;
    cin >> N >> M;
    string address, password;
    while (N--)
    {
        cin >> address >> password;
        info[address] = password;
    }

    while (M--)
    {
        cin >> address;
        cout << info[address] << endl;
    }
    return 0;
}