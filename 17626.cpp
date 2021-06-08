#include<stdio.h>
#include<math.h>
#define INF 987654321

int dp[50001];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=2;i<=50000;i++){
        dp[i]=INF;
    }
    dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=sqrt(i);j>=1;j--){
            int tmp=1+dp[i-j*j];
            if(tmp<dp[i])dp[i]=tmp;
        }
    }
    printf("%d",dp[n]);
    return 0;
}