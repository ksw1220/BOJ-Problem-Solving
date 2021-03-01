#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[500001];
int cnt[8005];
int main() {
	int N;
	float sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	sort(arr, arr + N);
	printf("%.0f\n", sum / N);
	printf("%d\n", arr[N / 2]);
	for (int i = 0; i < N; i++) {
		cnt[arr[i] + 4000]++;
	}
	int f_idx=0;
	for (int i = 0; i < 8002; i++) {
		if (cnt[f_idx] < cnt[i])f_idx = i;
	}
	for (int i = 0; i <8002; i++) {
		if (i == f_idx)continue;
		if (cnt[f_idx] == cnt[i]) {
			f_idx = i;
			break;
		}
	}
	printf("%d\n", f_idx-4000);
	printf("%d\n", arr[N - 1] - arr[0]);
	return 0;
}