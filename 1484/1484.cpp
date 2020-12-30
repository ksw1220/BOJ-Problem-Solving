#include<stdio.h>
#include<vector>
using namespace std;
int arr[5],v[7];
int main(){
	int T,max=0;
	scanf("%d",&T);
	while(T--){
		int ans=0;
		for(int i=1;i<=6;i++)v[i]=0;
		for(int i=0;i<4;i++){
			scanf("%d",&arr[i]);
			v[arr[i]]++;
		}
		int idx1=0,idx2=0;
		for(int i=1;i<=6;i++){
			if(v[i]>=v[idx1]){
				idx2=idx1;
				idx1=i;
			}
			else if(v[i]>=v[idx2]){
				idx2=i;
			}
		}
		if(v[idx1]==4){
			ans=50000+idx1*5000;
		}
		else if(v[idx1]==3){
			ans=10000+idx1*1000;
		}
		else if(v[idx1]==2){
			if(v[idx2]==2)
				ans=2000+idx1*500+idx2*500;
			else ans=1000+idx1*100;
		}
		else ans=idx1*100;
		if(max<ans)max=ans;
	}
	printf("%d\n",max);
	return 0;
}
