#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
struct s{
	int age, order;
};
string Name[100001];
s arr[100001];
bool myfunction(s a, s b) {
	if (a.age == b.age)return a.order < b.order;
	else return a.age < b.age;
}
int main() {
	int N, tmp;
	string str;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		cin >> str;
		arr[i] = { tmp,i };
		Name[i] = str;
	}
	sort(arr, arr + N, myfunction);
	for (int i = 0; i < N; i++) {
		cout << arr[i].age << " " << Name[arr[i].order];
		printf("\n");
	}
	return 0;
}