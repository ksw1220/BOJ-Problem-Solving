#include<stdio.h>
#include<algorithm>
using namespace std;
int  C[10001];
int main() {
	int N, tmp, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		M = max(M, tmp);
		C[tmp]++;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < C[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}