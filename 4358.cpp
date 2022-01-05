#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> species;

int main()
{
    string name;
    float cnt = 0;
    while (getline(cin, name))
    {
        species[name]++;
        cnt += 1;
    }

    map<string, int>::iterator it;
    for (it = species.begin(); it != species.end(); it++)
    {
        float rate = (float)(*it).second / cnt * 100;
        cout << (*it).first << " ";
        printf("%.4f\n", rate);
    }
    return 0;
}