#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main() {
	int cnt = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.length();i++) {
		if (i < str.length() - 2) {
			if (str[i] == 'd'&&str[i + 1] == 'z'&&str[i + 2] == '=')i += 2;
		}
		if (i < str.length() - 1) {
			if (str[i] == 'c'&&str[i+1] == '=') i++;
			else if (str[i] == 'c'&&str[i+1] == '-') i++;
			else if (str[i] == 'd'&&str[i+1] == '-') i++;
			else if (str[i] == 'l'&&str[i+1] == 'j') i++;
			else if (str[i] == 'n'&&str[i+1] == 'j') i++;
			else if (str[i] == 's'&&str[i+1] == '=') i++;
			else if (str[i] == 'z'&&str[i+1] == '=') i++;
		}
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}