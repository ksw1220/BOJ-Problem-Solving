#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
char card[1001];
vector<char> v;
int main() {
	int T, N;
	string str;
	scanf("%d", &T);
	while (T--) {
		v.clear();
		cin >> N;
		for (int i = 1; i <= N; i++)cin >> card[i];
		v.push_back(card[1]);
		for (int i = 2; i <= N; i++) {
			if (v[0] >= card[i])v.insert(v.begin(), card[i]);
			else v.push_back(card[i]);
		}
		for (int i = 0; i < v.size(); i++)printf("%c", v[i]);
		printf("\n");
	}
	return 0;
}