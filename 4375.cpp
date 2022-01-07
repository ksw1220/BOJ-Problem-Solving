#include <iostream>
using namespace std;

int main()
{
    int N;
    while (cin>>N)
    {
        int cnt = 1, num = 1;
        while (1)
        {
            num %= N;
            if (num == 0)
            {
                break;
            }
            num = num*10+1;
            cnt++;
        }

        cout << cnt << endl;
    }
    return 0;
}