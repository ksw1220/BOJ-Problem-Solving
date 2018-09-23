#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int alpha[26];
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		int tmp = str[i] - 'a';
		if (tmp < 0) {
			alpha[str[i] - 'A']++;
		}
		else alpha [tmp]++;
	}
	int max = 0, cnt = 0, idx = 0;
	for (int i = 0; i < 26; i++) {
		if (max < alpha[i]) {
			max = alpha[i];
			idx = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (max == alpha[i])cnt++;
	}
	if (cnt > 1) {
		printf("?");
	}
	else printf("%c", idx + 'A');
	return 0;
}