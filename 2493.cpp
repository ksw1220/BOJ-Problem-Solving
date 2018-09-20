#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
stack<int> st;
int num[500001];
int ans[500001];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)scanf("%d", &num[i]);
	for (int i = 1; i <= N; i++) {
		while (!st.empty() && num[st.top()] < num[i])st.pop();
		if (st.empty())ans[i] = 0;
		else ans[i] = st.top();
		st.push(i);
	}
	for (int i = 1; i <= N; i++)printf("%d ", ans[i]);
	return 0;
}