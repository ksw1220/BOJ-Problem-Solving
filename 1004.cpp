#include <stdio.h>
#include <vector>

using namespace std;

typedef struct Circle
{
    int x, y, r;
}Circle;

vector<Circle> circles;

int x1, y1, x2, y2;

int distance(int X1, int Y1, int X2, int Y2)
{
    return (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2);
}
int isInCircle(int idx)
{
    int cnt = 0;

    Circle circle = circles[idx];

    if (distance(x1, y1, circle.x, circle.y) < circle.r * circle.r)
        cnt++;
    if (distance(x2, y2, circle.x, circle.y) < circle.r * circle.r)
        cnt++;

    return cnt;
}
int main()
{
    int T;
    int n, x, y, r;
    scanf("%d", &T);
    while (T--)
    {
        int answer = 0;
        circles.clear();
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &x, &y, &r);
            circles.push_back({x, y, r});
        }
        for (int i = 0; i < n; i++)
        {
            if (isInCircle(i) == 1)
            {
                answer++;
            }
        }

        printf("%d\n", answer);
    }

    return 0;
}