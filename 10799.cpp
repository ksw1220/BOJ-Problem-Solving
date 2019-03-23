#include<stdio.h>
#include<stack>
#include<string>
#include<iostream>
using namespace std;
stack<int> st;
int main() {
	string input;
	cin >> input;
	int ans = 0;
	int len = input.length();
	for (int i = 0; i < len; i++) {
		if (input[i] == '(') {
			st.push(i);
			ans++;
		}
		else {
			if (st.top() == i - 1) {
				st.pop();
				ans--;
				ans += st.size();
			}
			else st.pop();
		}
	}
	printf("%d", ans);
	return 0;
}