#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;

int main(){
    priority_queue<int> positive;
    priority_queue<int> negative;

    int N,x;
    cin>>N;

    for(int i=0;i<N;i++){
        scanf("%d",&x);
        if(x==0){
            if(positive.empty()&&negative.empty()){
                printf("0\n");
            }
            else if(positive.empty()){
                printf("%d\n",negative.top());
                negative.pop();
            }
            else if(negative.empty()){
                printf("%d\n",-positive.top());
                positive.pop();
            }
            else{
                int pos=-positive.top();
                int neg=-negative.top();
                if(neg<=pos){
                    printf("%d\n",-neg);
                    negative.pop(); 
                }
                else{
                    printf("%d\n",pos);
                    positive.pop();
                }
            }
        }
        else if(x>0)
            positive.push(-x);
        else 
            negative.push(x);
    }
    return 0;
}