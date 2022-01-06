#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll gcd(ll a, ll b)
{
    if (b)
        return gcd(b, a % b);
    else
        return a;
}
pair<ll, ll> ext_gcd(ll a, ll b)
{
    if (b)
    {
        pair<ll, ll> tmp = ext_gcd(b, a % b);
        return {tmp.second, tmp.first - (a / b) * tmp.second};
    }
    else
        return {1, 0};
}
ll mod_inverse(ll a, ll M)
{
    return (ext_gcd(a, M).first + M) % M;
}
int main()
{
    int T;
    ll K, C;
    cin >> T;
    while (T--)
    {
        cin >> K >> C;
        if (gcd(C, K) != 1)
        {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }
        // Cx = 1 (mod K) 를 구하는 문제이지만 사탕을 K명에게 나누어주려면 Cx > K 이어야 하겠죠.
        ll ans = mod_inverse(C, K);
        while (C * ans <= K)
            ans += K;
        if (ans > 1e9)
            cout << "IMPOSSIBLE" << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}