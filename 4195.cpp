#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
int F, T;
map<string, string> parent;
map<string, int> num_fr;
string a, b;
string func(string x) {
	if (parent[x] == x)return x;
	else return parent[x] = func(parent[x]);
}
char aa[21], bb[21];
int main() {
	cin >> T;
	while (T--) {
		num_fr.clear();
		parent.clear();
		scanf("%d", &F);
		while (F--) {
			scanf("%s %s", aa, bb);
			a = (string)aa;
			b = (string)bb;
			if (parent.find(a) == parent.end()) parent[a] = a;
			if (parent.find(b) == parent.end()) parent[b] = b;
			if (num_fr.find(a) == num_fr.end())num_fr[a] = 1;
			if (num_fr.find(b) == num_fr.end())num_fr[b] = 1;
			a = func(a);
			b = func(b);
			if (a == b)printf("%d\n", num_fr[b]);
			else {
				parent[a] = b;
				num_fr[b] += num_fr[a];
				printf("%d\n", num_fr[b]);
			}
		}
	}
	return 0;
}