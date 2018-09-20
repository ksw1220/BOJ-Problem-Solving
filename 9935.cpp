#include<iostream>
#include<string>
using namespace std;
char st[1000001];
int top = 0;
int main() {
	string str, bomb;
	cin >> str >> bomb;
	int bLen = bomb.length();
	for (int i = 0; i < str.length(); i++) {
		char now = str[i];
		if (top >=bLen) {
			bool chk = true;
			if (st[top] == bomb[bLen - 1]) {
				for (int j = 0; j < bLen; j++) {
					if (bomb[j] != st[top - (bLen - 1) + j]) {
						chk = false;
						break;
					}
				}
				if (chk) {
					top -= bLen;
				}
			}
		}
		st[++top] = now;
	}
	if (top >= bLen) {
		bool chk = true;
		if (st[top] == bomb[bLen - 1]) {
			for (int j = 0; j < bLen; j++) {
				if (bomb[j] != st[top - (bLen - 1) + j]) {
					chk = false;
					break;
				}
			}
			if (chk) {
				top -= bLen;
			}
		}
	}
	if (top == 0)printf("FRULA");
	else for (int i = 1; i <= top; i++)printf("%c", st[i]);
	return 0;
}