#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;

vector<int> prime, number;
vector<vector<int>> primeFactor;
vector<int> sumFactor;
vector<bool> isPrime;

void primeFactoriztion(int idx)
{
    int x = number[idx];
    for (int i = 0; i < prime.size(); i++)
    {
        int cnt = 0;
        if (x < prime[i])
        {
            break;
        }
        while (x % prime[i] == 0)
        {
            cnt++;
            x /= prime[i];
        }
        primeFactor[idx][i] = cnt;
        sumFactor[i] += cnt;
    }
}
int main()
{
    int N, x, answer = 1, cnt = 0;
    cin >> N;

    isPrime.assign(MAX + 1, true);
    number.assign(N, 0);
    for (int i = 2; i * i <= MAX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i + i; j <= MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAX; i++)
    {
        if (isPrime[i])
            prime.push_back(i);
    }
    sumFactor.assign(prime.size(), 0);
    primeFactor.assign(N, vector<int>(prime.size(), 0));
    for (int i = 0; i < N; i++)
    {
        cin >> number[i];
        primeFactoriztion(i);
    }

    for (int i = 0; i < sumFactor.size(); i++)
    {
        int numFactor = sumFactor[i] / N;
        for (int j = 0; j < N; j++)
        {
            if (primeFactor[j][i] < numFactor)
            {
                cnt += numFactor - primeFactor[j][i];
            }
        }
        if (numFactor)
        {
            while (numFactor--)
            {
                answer *= prime[i];
            }
        }
    }
    cout << answer << " " << cnt << endl;

    return 0;
}