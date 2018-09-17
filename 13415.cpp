#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
stack<pair<int, int>> st;
int arr[100001];
pair<int, int> ans[200001];
vector<pair<int, int>> query;
int main() {
	int N, K, num, sorting;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &K);
	int a, b;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &a, &b);
		query.push_back({ a,0 });
		query.push_back({ b,1 });
	}
	for (int i = 0; i < query.size(); i++) {
		int now = query[i].first;
		while (!st.empty() && st.top().first <= now)
			st.pop();
		st.push({ query[i].first,query[i].second });
	}
	int S = st.size();
	int size = 0;
	while (!st.empty()) {
		ans[S - size - 1].first = st.top().first;
		ans[S - size - 1].second = st.top().second;
		st.pop();
		size++;
	}
	for (int i = 0; i < size; i++) {
		int to = ans[i].first;
		sort(arr, arr + to);
		if (ans[i].second == 1) {
			reverse(arr, arr + to);
		}
	}
	for (int i = 0; i < N; i++)printf("%d ", arr[i]);
	return 0;
}