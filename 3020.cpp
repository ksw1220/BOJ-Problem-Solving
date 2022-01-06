#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<int> odd, even;
vector<vector<int>> huddles;
bool compare(int a, int b)
{
    return a > b;
}
void printV(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, H;
    int min = INF, cnt = 0;
    cin >> N >> H;

    odd.assign(N / 2, 0);
    even.assign(N / 2, 0);
    huddles.assign(H + 1, vector<int>(2, 0));

    for (int i = 0; i < N / 2; i++)
    {
        cin >> odd[i];
        cin >> even[i];
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end(), compare);

    for (int i = 0, j = 1; j <= H; j++)
    {
        while (i < N / 2 && j > odd[i])
        {
            i++;
        }
        huddles[j][0] = N / 2 - i;
    }
    for (int i = 0, j = 1; j <= H; j++)
    {
        while (i < N / 2 && j > H - even[i])
        {
            i++;
        }
        huddles[j][1] = i;
    }

    for (int i = 1; i <= H; i++)
    {
        min = min < huddles[i][0] + huddles[i][1] ? min : huddles[i][0] + huddles[i][1];
    }
    for (int i = 1; i <= H; i++)
    {
        if (min == huddles[i][0] + huddles[i][1])
        {
            cnt++;
        }
    }

    cout << min << " " << cnt << endl;

    return 0;
}