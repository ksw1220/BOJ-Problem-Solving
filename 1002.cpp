#include<stdio.h>
#include<algorithm>
using namespace std;
int D[2][3];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int ans, d, rd, Md, md, cd;
		for (int i = 0; i < 2; i++)for (int j = 0; j < 3; j++)scanf("%d", &D[i][j]);
		d = (D[0][0] - D[1][0])*(D[0][0] - D[1][0]) + (D[0][1] - D[1][1])*(D[0][1] - D[1][1]);
		rd = (D[0][2] + D[1][2])*(D[0][2] + D[1][2]);
		cd = (D[0][2] - D[1][2])*(D[0][2] - D[1][2]);
		Md = max(D[0][2], D[1][2]);
		md = min(D[0][2], D[1][2]);
		if (D[0][0] == D[1][0] && D[0][1] == D[1][1]) {
			if (D[0][2] == D[1][2])ans = -1;
			else ans = 0;
		}
		else {
			if (Md > d) {
				if (d < cd)ans = 0;
				else if (d == cd)ans = 1;
				else ans = 2;
			}
			else if (Md == d)ans = 2;
			else {
				if (d < rd)ans = 2;
				else if (d == rd)ans = 1;
				else ans = 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}