#include<stdio.h>
#include<algorithm>
using namespace std;
int num[1001];
int main() {
	int N, ans = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &num[i]);
	sort(num, num + N);
	for (int i = 0; i < N; i++) {
		ans += num[i] * (N - i);
	}
	printf("%d", ans);
	return 0;
}