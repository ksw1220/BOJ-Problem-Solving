#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<char> st;
int main() {
	string s;
	cin >> s;
	int ans = 0, mul = 1;
	for (int i = 0; i < s.length(); i++) {
		char tmp = s[i];
		if (tmp == '(') {
			st.push('(');
			mul *= 2;
			if (i + 1 < s.length() && s[i + 1] == ')')
				ans += mul;
		}
		else if (tmp == '[') {
			st.push('[');
			mul *= 3;
			if (i + 1 < s.length() && s[i + 1] == ']')
				ans += mul;
		}
		else if (tmp == ')') {
			if (st.empty() || st.top() != '(') {
				cout << 0;
				return 0;
			}
			st.pop();
			mul /= 2;
		}
		else if (tmp == ']') {
			if (st.empty() || st.top() != '[') {
				cout << 0;
				return 0;
			}
			st.pop();
			mul /= 3;
		}
	}
	if (!st.empty())cout << 0;
	else cout << ans;
	return 0;
}