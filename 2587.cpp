#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[5];
int main() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	sort(arr, arr + 5);
	printf("%d\n%d\n", sum / 5, arr[2]);
	return 0;
}