#include<stdio.h>
int score[2][10];
int main() {
	int a, b;
	a = b = 0;
	for (int i = 0; i < 2; i++)for (int j = 0; j < 10; j++)scanf("%d", &score[i][j]);
	for (int i = 0; i < 10; i++) {
		if (score[0][i] > score[1][i])a++;
		else if (score[0][i] < score[1][i])b++;
	}
	if (a > b) printf("A");
	else if (a < b)printf("B");
	else printf("D");
	return 0;
}