#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    string strings[51];

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> strings[i];
    }

    string pivot = strings[0];
    string answer = "";
    for (int i = 0; i < pivot.length(); i++)
    {
        bool chk = true;
        for (int j = 1; j < N; j++)
        {
            if (pivot[i] != strings[j][i])
            {
                chk = false;
                break;
            }
        }
        if (chk)
        {
            answer += pivot[i];
        }
        else
        {
            answer += '?';
        }
    }

    cout << answer << endl;
    return 0;
}