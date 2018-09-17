#include<stdio.h>
int main() {
	int sum;
	scanf("%d", &sum);
	for (int i = 0; i < 9; i++) {
		int tmp;
		scanf("%d", &tmp);
		sum -= tmp;
	}
	printf("%d", sum);
	return 0;
}