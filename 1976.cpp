#include<stdio.h>
int graph[201][201];
int parent[201], num[201], path[1001];
int find(int now) {
	if (parent[now] == now)return now;
	return parent[now] = find(parent[now]);
}
int main() {
	int N, M, a, b, c;
	bool chk = true;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		num[i] = 1;
	}
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++) scanf("%d", &graph[i][j]);
	for (int i = 1; i <= N; i++)for (int j = i + 1; j <= N; j++) {
		if (graph[i][j] == 0)continue;
		int A = find(i); int B = find(j);
		if (num[A] >= num[B]) {
			parent[B] = A;
			num[A] += num[B];
		}
		else {
			parent[A] = B;
			num[B] += A;
		}
	}
	for (int i = 0; i < M; i++)scanf("%d", &path[i]);
	int ans = find(path[0]);
	for (int i = 1; i < M; i++) {
		if (ans != find(path[i])) {
			chk = false;
			break;
		}
	}
	if (chk)printf("YES");
	else printf("NO");
	return 0;
}