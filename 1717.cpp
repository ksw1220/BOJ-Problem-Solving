#include <stdio.h>
#include <vector>

using namespace std;

vector<int> parent;
int find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return parent[x] = find(parent[x]);
	}
}
int main()
{
	int N, M, op, a, b;
	scanf("%d %d", &N, &M);
	for (int i = 0; i <= N; i++)
	{
		parent.push_back(i);
	}
	while (M--)
	{
		scanf("%d %d %d", &op, &a, &b);
		a = find(a);
		b = find(b);
		if (op == 0)
		{
			parent[a] = b;
		}
		else if (op == 1)
		{
			if (a == b)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}
