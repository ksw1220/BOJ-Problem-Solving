#include<iostream>
using namespace std;

int gcd(int a,int b){
    if(b==0)
        return a;
    else 
        return gcd(b,a%b);
}

int main(){
    int T,M,N,x,y;
    cin>>T;
    while(T--){
        cin>>M>>N>>x>>y;
        int k=x,end,answer=-1;
        end=M*N/gcd(M,N);
        
        while(k<=end){
            int a=k%M,b=k%N;
            if(a==0) a=M;
            if(b==0) b=N;
            if(a==x&&b==y){
                answer=k;
                break;
            }
            k+=M;
        }
        printf("%d\n",answer);
    }
    return 0;
}