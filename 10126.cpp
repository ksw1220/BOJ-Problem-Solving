#include<stdio.h>
int main() {
	int T;
	scanf("%d", &T);
	if (T % 10 != 0) {
		printf("-1");
		return 0;
	}
	printf("%d ", T / 300);
	T = T % 300;
	printf("%d ", T / 60);
	T = T % 60;
	printf("%d ", T / 10);
	return 0;
}