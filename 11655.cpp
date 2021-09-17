#include <iostream>
#include <string>
using namespace std;
int main()
{
    string w;
    getline(cin, w);
    for (int i = 0; i < w.size(); i++)
    {
        if (isalpha(w[i]))
        {
            if (w[i] < 78)
                printf("%c", w[i] + 13);
            else if (w[i] >= 79 && w[i] <= 90)
                printf("%c", w[i] - 13);
            else if (w[i] >= 97 && w[i] < 110)
                printf("%c", w[i] + 13);
            else
                printf("%c", w[i] - 13);
        }
        else
            printf("%c", w[i]);
    }
}