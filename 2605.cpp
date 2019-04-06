#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v;
int main() {
	int N, K;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &K);
		v.insert(v.end() - K, i);
	}
	for (int i = 0; i < v.size(); i++)printf("%d ", v[i]);
	return 0;
}