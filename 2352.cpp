#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ports;
vector<int> LIS;
int main()
{
    int N, answer = 0;
    cin >> N;
    ports.assign(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> ports[i];
    }

    LIS.push_back(ports[0]);

    for (int i = 1; i < N; i++)
    {
        int idx = (lower_bound(LIS.begin(), LIS.end(), ports[i]) - LIS.begin());
        if (idx == LIS.size())
        {
            LIS.push_back(ports[i]);
        }
        else
        {
            LIS[idx] = ports[i];
        }
    }
    cout << LIS.size() << endl;
    return 0;
}