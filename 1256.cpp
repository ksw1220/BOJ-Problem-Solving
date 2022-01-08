#include <iostream>
#include <vector>
#include <string>
#define INF 1000000001
using namespace std;

vector<vector<int>> comb;
int main()
{
    int N, M, K;
    int a = 0, z = 0;
    string answer = "";
    cin >> N >> M >> K;

    comb.assign(N + M + 1, vector<int>(N + M + 1, 1));

    for (int i = 2; i <= N + M; i++)
    {
        for (int j = 1; j < i; j++)
        {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            if (comb[i][j] >= INF)
            {
                comb[i][j] = INF;
            }
        }
    }

    if (comb[N + M][N] < K)
    {
        cout << -1 << endl;
    }
    else
    {
        while (K)
        {
            if (answer.length() == N + M)
            {
                break;
            }
            if (a == N)
            {
                answer += "z";
                z++;
                continue;
            }
            int standard = comb[N + M - a - z - 1][N - a - 1];
            if (standard >= K)
            {
                answer += "a";
                a++;
            }
            else
            {
                answer += "z";
                K -= standard;
                z++;
            }
        }
        cout << answer << endl;
    }

    return 0;
}
