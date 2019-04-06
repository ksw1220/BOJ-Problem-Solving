#include<stdio.h>
int count[10];
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int mul = a * b*c;
	while (mul) {
		count[mul % 10]++;
		mul /= 10;
	}
	for (int i = 0; i < 10; i++)printf("%d\n", count[i]);
	return 0;
}