#include<stdio.h>
#include<vector>
using namespace std;
int arr[21];
void reverse(int left, int right) {
	vector<int> v;
	int start = right;
	for (int i = left; i <= right; i++)v.push_back(arr[i]);
	for (int i = 0; i < v.size(); i++)arr[start--] = v[i];
}
int main() {
	int a, b;
	for (int i = 1; i <= 20; i++)arr[i] = i;
	for (int i = 0; i < 10; i++) {
		scanf("%d %d", &a, &b);
		reverse(a, b);
	}
	for (int i = 1; i <= 20; i++)printf("%d ", arr[i]);
	return 0;
}