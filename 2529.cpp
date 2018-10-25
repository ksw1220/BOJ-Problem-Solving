#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> graph[11];
priority_queue<int> pq;
int in1[11], in2[11];
int min_topol[11], max_topol[11];
int ans1[11], ans2[11];
int main() {
	int N, cnt = 0, num = 0;
	char tmp;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		if (tmp == '<') {
			graph[i].push_back(i - 1);
			in1[i - 1]++;
			in2[i - 1]++;
		}
		else if (tmp == '>') {
			graph[i - 1].push_back(i);
			in1[i]++;
			in2[i]++;
		}
	}
	for (int i = 0; i <= N; i++) if (in1[i] == 0)pq.push(i);
	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();
		min_topol[cnt++] = now;
		for (int i = 0; i < graph[now].size(); i++) {
			int to = graph[now][i];
			if (--in1[to] == 0)pq.push(to);
		}
	}
	for (int i = cnt - 1; i >= 0; i--) {
		ans1[min_topol[i]] = num++;
	}
	cnt = 0;
	for (int i = 0; i <= N; i++) if (in2[i] == 0)pq.push(-i);
	while (!pq.empty()) {
		int now = -pq.top();
		pq.pop();
		max_topol[cnt++] = now;
		for (int i = 0; i < graph[now].size(); i++) {
			int to = graph[now][i];
			if (--in2[to] == 0)pq.push(-to);
		}
	}
	num = 9;
	for (int i = 0; i < cnt; i++) {
		ans2[max_topol[i]] = num--;
	}
	for (int i = 0; i < cnt; i++)printf("%d", ans2[i]);
	printf("\n");
	for (int i = 0; i < cnt; i++)printf("%d", ans1[i]);
	return 0;
}