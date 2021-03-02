#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string str;
	while (1) {
		getline(cin, str);
		if (str == ".")break;
		stack<int> st;
		bool chk = true;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(')st.push(1);
			else if (str[i] == '[')st.push(2);
			else if (str[i] == ')') {
				if (st.empty() || st.top() != 1) {
					chk = false;
					break;
				}
				st.pop();
			}
			else if (str[i] == ']') {
				if (st.empty() || st.top() != 2) {
					chk = false;
					break;
				}
				st.pop();
			}
		}
		if (!st.empty())chk = false;
		if (chk)cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}