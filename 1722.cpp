#include <iostream>
#include <vector>

using namespace std;

vector<long long> factorial;
vector<int> permutation;
vector<bool> visited;
void getFactorial(long long n)
{
    factorial[0] = factorial[1] = 1;
    for (long long i = 2; i <= n; i++)
    {
        factorial[i] = factorial[i - 1] * i;
    }
}
int main()
{
    int N, K;
    cin >> N;
    factorial.assign(N + 1, 0);
    visited.assign(N + 1, false);
    cin >> K;
    getFactorial(N);
    if (K == 1)
    {
        long long order;
        int number;
        cin >> order;
        for (int i = 1; i <= N; i++)
        {
            number = order / factorial[N - i];
            if (order % factorial[N - i])
            {
                number++;
            }
            order = order - (number - 1) * factorial[N - i];
            for (int i = 1; i <= N; i++)
            {
                if (!visited[i])
                {
                    number--;
                    if (!number)
                    {
                        permutation.push_back(i);
                        visited[i] = true;
                        break;
                    }
                }
            }
        }
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                permutation.push_back(i);
            }
        }
        for (int i = 0; i < permutation.size(); i++)
        {
            cout << permutation[i] << " ";
        }
        cout << endl;
    }
    else if (K == 2)
    {
        long long order = 0;
        long long number, idx;
        for (int i = 1; i <= N; i++)
        {
            cin >> number;
            idx = number;
            for (int j = 1; j <= N; j++)
            {
                if (visited[j] && number > j)
                {
                    idx--;
                }
            }
            visited[number] = true;

            order += factorial[N - i] * (idx - 1);
        }

        cout << order + 1 << endl;
    }
    return 0;
}