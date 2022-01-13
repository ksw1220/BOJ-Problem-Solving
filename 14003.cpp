#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> A, pre, v, vIndex;
stack<int> answer;
int main()
{
	int N, track;
	scanf("%d", &N);
	A.resize(N);
	pre.resize(N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	v.push_back(A[0]);
	vIndex.push_back(0);
	pre[0] = -1;

	for (int i = 1; i < N; i++)
	{
		int idx = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
		if (idx == v.size())
		{
			v.push_back(A[i]);
			vIndex.push_back(i);
			pre[i] = vIndex[idx - 1];
		}
		else
		{
			v[idx] = A[i];
			vIndex[idx] = i;
			if (idx == 0)
			{
				pre[i] = -1;
			}
			else
			{
				pre[i] = vIndex[idx - 1];
			}
		}
	}

	track = vIndex[vIndex.size() - 1];

	while (track != -1)
	{
		answer.push(track);
		track = pre[track];
	}

	printf("%d\n", (int)answer.size());
	while (!answer.empty())
	{
		printf("%d ", A[answer.top()]);
		answer.pop();
	}
	return 0;
}