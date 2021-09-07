#include <iostream>
#include <vector>

using namespace std;

long long numberOfOne(long long x)
{
    long long mul = 1;
    long long sum = 0;
    while (mul <= x)
    {
        long long Q = x / mul;
        if (Q % 2 == 1)
        {
            sum += ((Q - 1) * mul / 2);
            sum += x % mul + 1;
        }
        else
        {
            sum += (Q * mul / 2);
        }
        mul *= 2;
    }
    return sum;
}
int main()
{
    long long A, B;

    cin >> A >> B;

    cout << numberOfOne(B) - numberOfOne(A - 1) << endl;
    return 0;
}