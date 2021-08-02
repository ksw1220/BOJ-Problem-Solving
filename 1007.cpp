#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

vector<int> X;
vector<int> Y;
int N;
double answer = 1e10;

void dfs(int cnt, int positive, int negative, int x, int y)
{
    if (cnt == N)
    {
        double tmp = sqrt(pow(x, 2) + pow(y, 2));

        if (answer > tmp)
        {
            answer = tmp;
        }

        return;
    }

    if (positive < N / 2)
    {
        dfs(cnt + 1, positive + 1, negative, x + X[cnt], y + Y[cnt]);
    }
    if (negative < N / 2)
    {
        dfs(cnt + 1, positive, negative + 1, x - X[cnt], y - Y[cnt]);
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        answer = 1e10;
        scanf("%d", &N);
        X.assign(N, 0);
        Y.assign(N, 0);
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &X[i], &Y[i]);
        }
        dfs(0, 0, 0, 0, 0);

        printf("%.8lf\n", answer);
    }

    return 0;
}