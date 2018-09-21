#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct sch{ int start, end; };
vector<sch> T;
bool myfunction(sch A, sch B) {
	if (A.end == B.end) {
		return (A.start < B.start);
	}
	else return (A.end < B.end);
}
int main() {
	int N, s, e, ans = 0, now;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &s, &e);
		T.push_back({ s,e });
	}
	sort(T.begin(), T.end(), myfunction);
	now = T[0].end;
	ans = 1;
	for (int i = 1; i < N; i++) {
		if (now <= T[i].start) {
			ans++;
			now = T[i].end;
		}
	}
	printf("%d", ans);
	return 0;
}