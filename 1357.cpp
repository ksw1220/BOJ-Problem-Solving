#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int func(int now) {
	int re = 0;
	while (now > 0) {
		re *= 10;
		re += now % 10;
		now /= 10;
	}
	return re;
}
int main() {
	int X, Y;
	scanf("%d %d", &X, &Y);
	printf("%d", func(func(X) + func(Y)));
	return 0;
}