#include<stdio.h>
int main() {
	int N, cnt = 0;
	scanf("%d", &N);
	for (int i = 0; i < 5; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == N)cnt++;
	}
	printf("%d", cnt);
	return 0;
}