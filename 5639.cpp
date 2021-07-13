#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v;

void dfs(int left, int right)
{
    if (left > right)
        return;
    int val = v[left];
    int index = -1;
    for (index = left + 1; index <= right; index++)
    {
        if (val < v[index])
            break;
    }
    
    dfs(left + 1, index - 1);
    dfs(index, right);
    printf("%d\n", val);
}
int main()
{
    int x;
    while (scanf("%d", &x) != EOF)
    {
        v.push_back(x);
    }

    dfs(0, v.size() - 1);
    return 0;
}