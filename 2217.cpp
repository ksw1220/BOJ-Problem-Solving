#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int num[100001];
int main() {
	int N, ans = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + N);
	reverse(num, num + N);
	for (int i = 0; i < N; i++) {
		ans = max(ans, num[i] * (i + 1));
	}
	printf("%d", ans);
	return 0;
}