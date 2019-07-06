#include<stdio.h>
bool chk[2001][2001];
int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}
int main() {
	int D1, D2, a, b, cnt = 0;
	scanf("%d %d", &D1, &D2);
	for (int i = D1; i <= D2; i++) {
		for (int j = 1; j < i; j++) {
			int g = gcd(i, j);
			a = i / g;
			b = j / g;
			if (!chk[a][b]) {
				cnt++;
				chk[a][b] = true;
			}
		}
	}
	for (int i = 1; i <= D2; i++) {
		for (int j = 0; j <= D2; j++) {
			if (chk[i][j])printf("1 ");
			else printf("0 ");
		}
		printf("\n");
	}
	printf("%d", cnt + 1);
	return 0;
}