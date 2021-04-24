#include<stdio.h>
#include<string>
using namespace std;

int dis[10];
bool is_possible(int number) {
	bool re = true;
	if(number==0&&dis[0])
		re=false;
	while (number > 0) {
		int tmp = number % 10;
		if (dis[tmp]) {
			re = false;
			break;
		}
		number /= 10;
	}
	return re;
}
int main() {
	int N, d, ch;
	scanf("%d", &N);
	scanf("%d", &d);
	for (int i = 0; i < d; i++) {
		scanf("%d", &ch);
		dis[ch] = true;
	}
	int tmp_ch = 0;
	int ans = N-100;
	if(ans<0)ans*=-1;
	while (tmp_ch <=1000001) {
		if (is_possible(tmp_ch)) {
			string s=to_string(tmp_ch);
			int len=s.length();
			int diff=N-tmp_ch;
			if(diff<0)
				diff*=-1;
			
			if(ans>diff+len)ans=diff+len;	
		}
		tmp_ch++;
	}
	printf("%d", ans);
	return 0;
}