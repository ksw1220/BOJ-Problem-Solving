#include<stdio.h>
#include<algorithm>
using namespace std;
struct s {
	int x, y;
};
s v[100001];
bool myfunction(s a, s b) {
	if (a.y != b.y)return a.y < b.y;
	else return a.x < b.x;
}
int main() {
	int N, a, b;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		v[i].x = a, v[i].y = b;
	}
	sort(v, v + N, myfunction);
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", v[i].x, v[i].y);
	}
	return 0;
}