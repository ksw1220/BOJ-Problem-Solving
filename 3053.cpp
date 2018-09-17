#include<stdio.h>
#include<math.h>
int main() {
	double a, b;
	int N;
	scanf("%d", &N);
	N *= N;
	a = 3.141592653589793*N;
	b = 2.000000*N;
	printf("%.6lf\n", a);
	printf("%.6lf", b);
	return 0;
}