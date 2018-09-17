#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
string arr[6];
int main() {
	string tmp;
	for (int i = 0; i < 5; i++) {
		cin >> tmp;
		arr[i] = tmp;
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (i >= arr[j].length())continue;
			printf("%c", arr[j][i]);
		}
	}
	return 0;
}