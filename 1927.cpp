#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;

priority_queue<int> pq;
int main() {
	int N,input;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &input);
		if (input == 0) {
			if (pq.empty())printf("0\n");
			else {
				printf("%d\n", -pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(-input);
		}
	}
	return 0;
}