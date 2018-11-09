#include<stdio.h>
int root[100001];
int find(int now) {
	if (root[now] == now)return now;
	return root[now] = find(root[now]);
}
int main() {
	int G, P, tmp, ans = 0;
	scanf("%d %d", &G, &P);
	for (int i = 1; i <= G; i++)root[i] = i;
	for (int i = 0; i < P; i++) {
		scanf("%d", &tmp);
		int re = find(tmp);
		if (re == 0)break;
		root[re] = re - 1;
		ans++;
		find(re);
	}
	printf("%d", ans);
	return 0;
}