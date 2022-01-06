#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    int A1, B1, A2, B2, GCD;
    cin >> A1 >> B1;
    cin >> A2 >> B2;

    A1 = A1 * B2 + A2 * B1;
    B1 *= B2;

    GCD = gcd(A1, B1);

    cout << A1 / GCD << " " << B1 / GCD << endl;

    return 0;
}