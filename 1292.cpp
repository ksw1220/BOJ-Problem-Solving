#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v;
int main() {
	int A, B, ans = 0;
	scanf("%d %d", &A, &B);
	for (int i = 1; i <= B; i++) {
		for (int j = 1; j <= i; j++) {
			v.push_back(i);
		}
	}
	for (int i = A; i <= B; i++)ans += v[i - 1];
	printf("%d", ans);
	return 0;
}