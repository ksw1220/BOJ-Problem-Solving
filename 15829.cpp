#include<iostream>
#include<string>
using namespace std;
int a[51];
int main() {
	int N;
	long long ans=0;
	string str;
	cin >> N >> str;
	for (int i = 0; i < N; i++) {
		a[i] = str[i] - 'a' + 1;
	}
	for (int i = N - 1; i >= 0; i--) {
		ans *= 31;
		ans += (long long)a[i];
		ans %= 1234567891;
	}
	cout << ans;
	return 0;
}