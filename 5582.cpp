#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
int main()
{
    int answer = 0;
    string A, B;
    cin >> A >> B;
    A = " " + A;
    B = " " + B;
    dp.assign(A.length(), vector<int>(B.length(), 0));

    for (int i = 1; i < A.length(); i++)
    {
        for (int j = 1; j < B.length(); j++)
        {
            if (A[i] == B[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                answer = max(answer, dp[i][j]);
            }
        }
    }

    cout << answer << endl;
    return 0;
}