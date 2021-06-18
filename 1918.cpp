#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string str;
    stack<char> operators;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            operators.push('(');
        }
        else if (str[i] == ')')
        {
            while (operators.top() != '(')
            {
                printf("%c", operators.top());
                operators.pop();
            }
            operators.pop();
        }
        else if (str[i] == '+' || str[i] == '-')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                printf("%c", operators.top());
                operators.pop();
            }
            operators.push(str[i]);
        }
        else if (str[i] == '*' || str[i] == '/')
        {
            while (!operators.empty() && operators.top() != '(' && operators.top() != '+' && operators.top() != '-')
            {
                printf("%c", operators.top());
                operators.pop();
            }
            operators.push(str[i]);
        }
        else
            printf("%c", str[i]);
    }
    while (!operators.empty())
    {
        printf("%c", operators.top());
        operators.pop();
    }
    printf("\n");
    return 0;
}