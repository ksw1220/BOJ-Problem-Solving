#include<stdio.h>
#include<algorithm>
using namespace std;
struct can {
	int x, y;
};
can ran[100001];
bool myfunc(can a,can b) {
	return a.x < b.x;
}
int main() {
	int T, N;
	scanf("%d", &T);
	while (T--) {
		int ans = 1;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &ran[i].x, &ran[i].y);
		}
		sort(ran, ran + N, myfunc);
		int standard = ran[0].y;
		for (int i = 1; i < N; i++) {
			if (ran[i].y < standard) {
				standard = ran[i].y;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}