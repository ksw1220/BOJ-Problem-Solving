#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
stack<int> st;
vector<char> ans;
int arr[100001];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &arr[i]);
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		st.push(i);
		ans.push_back('+');
		while (!st.empty() && st.top() == arr[idx]) {
			ans.push_back('-');
			st.pop();
			idx++;
		}
	}
	if (idx == N) {
		for (int i = 0; i < ans.size(); i++)printf("%c\n", ans[i]);
	}
	else printf("NO");
	return 0;
}