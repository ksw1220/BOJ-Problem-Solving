#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main() {
	int max = 0, tmp;
	string A, B;
	cin >> A >> B;
	int a = A.length(), b = B.length();
	for (int i = 0; i < b - a + 1; i++) {
		tmp = 0;
		for (int j = 0; j < a; j++) {
			if (A[j] == B[i + j])tmp++;
		}
		max = max > tmp ? max : tmp;
	}
	printf("%d", b - (max + b - a));
	return 0;
}