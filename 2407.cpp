#include <iostream>
#include <string>

using namespace std;

string combination[102][102];

string sumString(string a, string b)
{
    string re = "";

    if (a.length() >= b.length())
    {
        while (a.length() != b.length())
        {
            b = "0" + b;
        }
    }
    else
    {
        while (a.length() != b.length())
        {
            a = "0" + a;
        }
    }

    int len = a.length();
    int carry = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        sum %= 10;
        char tmp = sum + '0';
        re = tmp + re;
    }
    if (carry == 1)
        re = "1" + re;
    return re;
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            combination[i][j] = "0";
        }
    }
    for (int i = 0; i <= N; i++)
    {
        combination[i][0] = combination[i][i] = "1";
    }
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            combination[i][j] = sumString(combination[i - 1][j], combination[i - 1][j - 1]);
        }
    }
    cout << combination[N][M] << endl;
    return 0;
}