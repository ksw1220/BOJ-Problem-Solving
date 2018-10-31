#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int num[1000001], dp[1000001], pre[1000001];
vector<int> v, index;
stack<int> ans;
int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)scanf("%d", &num[i]);
	v.push_back(num[0]);
	index.push_back(0);
	pre[0] = -1;
	for (int i = 1; i < N; i++) {
		int idx = lower_bound(v.begin(), v.end(), num[i]) - v.begin();
		if (idx == v.size()) {
			pre[i] = index[idx - 1];
			index.push_back(i);
			v.push_back(num[i]);
		}
		else {
			if (idx == 0)pre[i] = -1;
			else pre[i] = index[idx - 1];
			v[idx] = num[i];	
			index[idx] = i;
		}
	}
	int cnt = 0;
    int now = index[v.size() - 1];
	while (now != -1) {
		cnt++;
		ans.push(num[now]);
		now = pre[now];
	}
	printf("%d\n", cnt);
	while (!ans.empty()) {
		printf("%d ", ans.top());
		ans.pop();
	}
	return 0;
}