#include<stdio.h>
int main() {
	int N;
	int sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp)sum++;
		else sum--;
	}
	if (sum > 0)printf("Junhee is cute!");
	else printf("Junhee is not cute!");
	return 0;
}