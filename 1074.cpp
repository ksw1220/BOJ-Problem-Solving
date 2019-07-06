#include<stdio.h>
int map[65][65], cnt = 0, R, C;
int z(int l, int r, int t, int b, int size) {
	int w, h, cost;
	w = (l + r) / 2;
	h = (t + b) / 2;
	cost = 1 << 2 * (size - 1);
	if (size == 0)return 0;
	if (l <= R && R <= w) {
		if (t <= C && C <= h)
			return z(l, w, t, h, size - 1);
		if (h < C && C <= b)
			return cost * 2 + z(l, w, h + 1, b, size - 1);
	}
	if (t <= C && C <= h)
		return cost + z(w + 1, r, t, h, size - 1);
	if (h < C && C <= b)
		return cost * 3 + z(w + 1, r, h + 1, b, size - 1);

}
int main() {
	int N, tmp;
	scanf("%d %d %d", &N, &C, &R);
	tmp = 1 << N;
	printf("%d", z(0, tmp - 1, 0, tmp - 1, N));
	return 0;
}