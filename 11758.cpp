#include<stdio.h>
int main() {
	int x1, x2, x3, y1, y2, y3;
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d %d", &x3, &y3);
	int vx1, vx2, vy1, vy2;
	vx1 = x2 - x1; vy1 = y2 - y1;
	vx2 = x3 - x2; vy2 = y3 - y2;
	int cross = vx1*vy2 - vx2*vy1;
	if (cross > 0)printf("1");
	else if (cross < 0)printf("-1");
	else printf("0");
	return 0;
}