#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<long long> pq;
int prime[101];
int main() {
	int K, N;
	long long now;
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++) {
		scanf("%d", &prime[i]);
		pq.push(-prime[i]);
	}
	for (int iter = 0; iter < N; iter++) {
		now = -pq.top();
		pq.pop();
		for (int i = 0; i < K; i++) {
			pq.push(-now * prime[i]);
			if (now%prime[i] == 0)break;
		}
	}
	printf("%lld", now);
	return 0;
}