#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[1001][3];
int dp[1001][3];
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
	}
	dp[0][0]=arr[0][0];
	dp[0][1]=arr[0][1];
	dp[0][2]=arr[0][2];

	for(int i=1;i<N;i++){
		dp[i][0]=min(dp[i-1][1],dp[i-1][2])+arr[i][0];
		dp[i][1]=min(dp[i-1][0],dp[i-1][2])+arr[i][1];
		dp[i][2]=min(dp[i-1][1],dp[i-1][0])+arr[i][2];
	}
	int ans=min(min(dp[N-1][0],dp[N-1][1]),dp[N-1][2]);
	printf("%d\n",ans);
	return 0;
}
