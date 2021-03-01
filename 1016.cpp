#include<stdio.h>
bool chk[1000001];
int main(){
	long long min,max;
	int a,b;
	scanf("%lld %lld",&min,&max);
	int ans=max-min+1;
	for(long long i=2;i*i<=max;i++){
		for(long long j=(min/(i*i)+(min%(i*i)!=0))*i*i;j<=max;j+=i*i){
			if(!chk[j-min]){
				chk[j-min]=true;
				ans--;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
