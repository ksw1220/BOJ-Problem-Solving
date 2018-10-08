#include<stdio.h>
#include<iostream>
using namespace std;
int parent[10001];
bool chk[10001];
int main() {
	int N, a, b, T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		int ans = 0;
		for (int i = 0; i <= N; i++) {
			chk[i] = false;
			parent[i] = i;
		}
		for (int i = 0; i < N - 1; i++) {
			scanf("%d %d", &a, &b);
			parent[b] = a;
		}
		scanf("%d %d", &a, &b);
		int now = a;
		while (parent[now] != now) {
			chk[now] = true;
			now = parent[now];
		}
		chk[now] = true;
		now = b;
		while (1) {
			if (chk[now]) {
				ans = now;
				break;
			}
			now = parent[now];
		}
		printf("%d\n", ans);
	}
	return 0;
}