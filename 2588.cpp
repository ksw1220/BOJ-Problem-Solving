#include<stdio.h>
int bit[3];
int main() {
	int a, b, tmp, output, cnt = 0;
	scanf("%d %d", &a, &b);
	tmp = b;
	while (tmp) {
		bit[cnt++] = tmp % 10;
		tmp /= 10;
	}
	printf("%d\n", bit[0] * a);
	printf("%d\n", bit[1] * a);
	printf("%d\n", bit[2] * a);
	printf("%d\n", a*b);
	return 0;
}