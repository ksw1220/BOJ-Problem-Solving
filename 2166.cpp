#include <iostream>
#include <vector>
using namespace std;

typedef pair<long long, long long> POINT;
vector<POINT> points;

long long CCW(POINT a, POINT b, POINT c)
{
    return (long long)(a.first * b.second) + (b.first * c.second) + (a.second * c.first) - (b.first * a.second) - (c.first * b.second) - (a.first * c.second);
}

int main(void)
{
    int N;
    double answer = 0;
    scanf("%d", &N);
    points.resize(N);
    for (int i = 0; i < N; i++)
        scanf("%lld %lld", &points[i].first, &points[i].second);
    for (int i = 1; i < N - 1; i++)
    {
        answer += CCW(points[0], points[i], points[i + 1]) / (double)2;
    }
    if (answer < 0)
        answer *= -1;
    printf("%.1lf\n", answer);
    return 0;
}
