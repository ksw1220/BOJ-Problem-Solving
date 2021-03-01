#include<iostream>
using namespace std;

int main() {
	string num;
	while (1) {
		cin >> num;
		if (num == "0")break;
		int num_length = num.length();
		bool chk = true;
		for (int i = 0; i < num_length / 2; i++) {
			if (num[i] != num[num_length - 1 - i]) {
				chk = false;
				break;
			}
		}
		if (chk)cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}