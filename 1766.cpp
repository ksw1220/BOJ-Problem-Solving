#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int indegree[32001];
vector<int> graph[32001];
priority_queue<int> pq;
int main() {
	int N, M, a, b;
	scanf("%d %d", &N, &M);
	while (M--) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			pq.push(-i);
		}
	}
	while (!pq.empty()) {
		int now = -pq.top();
		pq.pop();
		printf("%d ", now);
		for (int i = 0; i < graph[now].size(); i++) {
			int to = graph[now][i];
			indegree[to]--;
			if (indegree[to] == 0)pq.push(-to);
		}
	}
	return 0;
}