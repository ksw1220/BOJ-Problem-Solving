#include<stdio.h>
int main() {
	int H, M, S, input;
	scanf("%d %d %d %d", &H, &M, &S, &input);
	S += input;
	while (S >= 60) {
		S -= 60;
		M++;
	}
	while (M >= 60) {
		M -= 60;
		H++;
	}
	while (H >= 24) {
		H -= 24;
	}
	printf("%d %d %d", H, M, S);
	return 0;
}