#include<stdio.h>
int dis[10];
bool is_possible(int number) {
	bool re = true;
	while (number > 0) {
		int tmp = number % 10;
		if (dis[tmp]) {
			re = false;
			break;
		}
		number /= 10;
	}
	return re;
}
int main() {
	int N, d, ch;
	scanf("%d", &N);
	scanf("%d", &d);
	for (int i = 0; i < d; i++) {
		scanf("%d", &ch);
		dis[ch] = true;
	}
	int tmp_ch = N;
	int down = 0, up = 0;
	bool d_chk = false, u_chk = false;
	while (tmp_ch >= 0) {
		if (is_possible(tmp_ch)) {
			d_chk = true;
			if (tmp_ch == 0)down++;
			else {
				while (tmp_ch > 0) {
					tmp_ch /= 10;
					down++;
				}
			}
			break;
		}
		tmp_ch--;
		down++;
	}
	tmp_ch = N;
	while (tmp_ch<=1000000) {
		if (is_possible(tmp_ch)) {
			u_chk = true;
			if (tmp_ch == 0)up++;
			else {
				while (tmp_ch > 0) {
					tmp_ch /= 10;
					up++;
				}
			}break;
		}
		tmp_ch++;
		up++;
	}
	int ans = N - 100;
	if (ans < 0)ans *= -1;
	if (d_chk&&ans > down)ans = down;
	if (u_chk&&ans > up)ans = up;
	printf("%d", ans);
	return 0;
}