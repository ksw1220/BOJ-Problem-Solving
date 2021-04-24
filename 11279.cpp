#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;

int main(){
    int N,x;
    priority_queue<int> pq;
    cin>>N;
    for(int i=0;i<N;i++){
        scanf("%d",&x);
        if(x==0){
            if(pq.empty()) printf("0\n");
            else {
                printf("%d\n",pq.top());
                pq.pop();
            }
        }
        else pq.push(x);
    }

    return 0;
}