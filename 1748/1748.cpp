#include<stdio.h>
#include<string>
#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int number;
	cin>>number;

	int answer=0;
	int n=to_string(number).length();
	for(int i=0;i<n;i++){
		answer+=number-pow(10,i)+1;
	}
	printf("%d",answer);
	return 0;
}
