#include<stdio.h>
int parent[1000001], num[1000001];
int find(int now) {
	if (parent[now] == now)return now;
	else return parent[now] = find(parent[now]);
}
int main() {
	int N, M, op, a, b;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		num[i] = 1;
	}
	while (M--) {
		scanf("%d %d %d", &op, &a, &b);
		int A, B;
		A = find(a); B = find(b);
		if (op == 0) {
			if (num[a] >= num[b]) {
				parent[A] = B;
			}
			else parent[B] = A;
		}
		else {
			if (A == B)printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}