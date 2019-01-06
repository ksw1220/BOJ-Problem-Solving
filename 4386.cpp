#include<stdio.h>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;
struct pos {
	float x, y;
};
pos star[101];
priority_queue<pair<float, pair<int, int>>> pq;
int root[101];
float ans;
float dist(int a, int b) {
	float re;
	re = (star[a].x - star[b].x)*(star[a].x - star[b].x) + (star[a].y - star[b].y)*(star[a].y - star[b].y);
	re = sqrt(re);
	return re;
}
int find(int now) {
	if (root[now] == now)return now;
	return root[now] = find(root[now]);
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%f %f", &star[i].x, &star[i].y);
		root[i] = i;
	}
	for (int i = 0; i < N - 1; i++)for (int j = i + 1; j < N; j++) {
		pq.push({ -dist(i,j),{i,j} });
	}
	while (!pq.empty()) {
		float nowDis = -pq.top().first;
		int start = pq.top().second.first;
		int end = pq.top().second.second;
		pq.pop();
		start = find(start), end = find(end);
		if (start == end)continue;
		root[end] = start;
		ans += nowDis;
	}
	printf("%.2f", ans);
	return 0;
}