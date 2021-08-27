#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
int main()
{
    string board[8];
    int answer = 0;

    for (int i = 0; i < 8; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 'F' && (i + j) % 2 == 0)
            {
                answer++;
            }
        }
    }

    printf("%d\n", answer);
    return 0;
}