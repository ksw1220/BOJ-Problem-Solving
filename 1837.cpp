#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prime;
vector<bool> isPrime;

bool isDivide(string s, int primeNumber)
{
    int R = 0;
    for (int i = 0; i < s.length(); i++)
    {
        R *= 10;
        R += (s[i] - '0');
        R %= primeNumber;
    }
    if (R == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string P;
    int K;

    cin >> P >> K;
    isPrime.assign(K + 1, true);
    for (int i = 2; i < K; i++)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
            for (int j = i + i; j < K; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int R = 0;

    for (int i = 0; i < prime.size(); i++)
    {
        if (isDivide(P, prime[i]))
        {
            cout << "BAD " << prime[i] << endl;
            return 0;
        }
    }
    cout << "GOOD" << endl;
    return 0;
}