#include <stdio.h>
#include <vector>

using namespace std;

vector<bool> isPrime;
vector<int> primes;
vector<long long> accPrimes;
int main()
{
    int N, answer = 0;
    scanf("%d", &N);
    isPrime.assign(N + 1, true);

    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = i + i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    accPrimes.push_back(0);
    for (int i = 0; i < primes.size(); i++)
    {
        accPrimes.push_back(accPrimes[i] + primes[i]);
    }

    int start = 1, end = 1;
    while (start <= end && end < accPrimes.size())
    {
        int sum = accPrimes[end] - accPrimes[start - 1];
        if (sum == N)
        {
            answer++;
            end++;
        }
        else if (sum < N)
        {
            end++;
        }
        else
        {
            start++;
        }
    }
    printf("%d\n", answer);
    return 0;
}