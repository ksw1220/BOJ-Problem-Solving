#include<iostream>
#include<string>
using namespace std;
int radix(char x) {
	if ('A' <= x&&x <= 'F')return 10 + (x - 'A');
	else return x - '0';
}
int main() {
	int ans = 0;
	string str;
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		ans *= 16;
		ans += radix(str[i]);
	}
	printf("%d", ans);
	return 0;
}