#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A, B, C, D;
vector<int> AB, CD;
int main()
{
    int N;
    long long answer = 0;
    cin >> N;
    A.assign(N, 0);
    B.assign(N, 0);
    C.assign(N, 0);
    D.assign(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            CD.push_back(C[i] + D[j]);
        }
    }
    sort(CD.begin(), CD.end());

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int l = 0, r = CD.size();
            while (l <= r)
            {
                int mid = (l + r) / 2;
                int val = A[i] + B[j] + CD[mid];

                if (val == 0)
                {
                    // cout<<A[i]<<" "<<B[j]<<" "<<CD[mid]<<endl;;
                    int left = lower_bound(CD.begin(), CD.end(), CD[mid]) - CD.begin();
                    int right = upper_bound(CD.begin(), CD.end(), CD[mid]) - CD.begin();
                    answer += right - left;
                    // cout<<"right left "<<right<<" "<<left<<endl<<endl;
                    break;
                }
                else if (val > 0)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
    }
    cout << answer << endl;
    return 0;
}