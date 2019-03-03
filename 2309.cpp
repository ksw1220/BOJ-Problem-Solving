#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int height[10];
vector<int> ans;
void makeAns(int x, int y) {
	for (int i = 1; i <= 9; i++) {
		if (i == x || i == y)continue;
		ans.push_back(height[i]);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)printf("%d\n", ans[i]);
}
int main() {
	int sum = 0;
	for (int i = 1; i <= 9; i++) {
		scanf("%d", &height[i]);
		sum += height[i];
	}
	for (int i = 1; i < 9; i++)for (int j = i + 1; j <= 9; j++) {
		int tmp = sum - height[i] - height[j];
		if (tmp == 100) {
			makeAns(i, j);
			return 0;
		}
	}
	return 0;
}