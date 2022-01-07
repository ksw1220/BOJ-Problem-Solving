#include <iostream>
#include <vector>
#include <stdio.h>
#define MAX 1000000
using namespace std;

vector<bool> isPrime;
vector<int> prime;
int main()
{
    int x;
    isPrime.assign(MAX + 1, true);

    for (int i = 2; i * i <= MAX; i++)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
            for (int j = i + i; j <= MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    while (1)
    {
        scanf("%d", &x);
        if (x == 0)
        {
            break;
        }
        for (int i = 1; i < prime.size(); i++)
        {
            if (isPrime[x - prime[i]])
            {
                printf("%d = %d + %d\n", x, prime[i], x - prime[i]);
                break;
            }
        }
    }

    return 0;
}