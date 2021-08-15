#include <stdio.h>
#include <vector>

using namespace std;

vector<int> root;

int find(int now)
{
    if (root[now] == now)
    {
        return now;
    }
    else
    {
        return root[now] = find(root[now]);
    }
}
int main()
{
    int N, M, a, b;
    int answer = 0;
    scanf("%d %d", &N, &M);

    for (int i = 0; i <= N; i++)
    {
        root.push_back(i);
    }

    for (int i = 1; i <= M; i++)
    {
        scanf("%d %d", &a, &b);
        if (answer)
            continue;
        int A = find(a);
        int B = find(b);

        if (A == B)
        {
            answer = i;
        }
        else
        {
            root[A] = B;
        }
    }

    printf("%d\n", answer);
    return 0;
}