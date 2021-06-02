#include<iostream>
#include<stdio.h>
using namespace std;

int key=0;
void add(int x){
    key|=1<<x;
}

void remove(int x){
    key&=~(1<<x);
}

void check(int x){
    (key & (1 << (x))) ? printf("1\n") :printf("0\n");
}

void toggle(int x){ 
    key = key ^ (1<<(x));
}

void all(){
    key = (1<<21) - 1;
}

void empty(){
    key = 0;
}
int main(){
    int M,x;
    cin>>M;
    string cmd;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(M--){
        cin>>cmd;
        if(cmd=="add"){
            cin>>x;
            add(x);
        }
        else if(cmd=="remove"){
            cin>>x;
            remove(x);
        }
        else if(cmd=="check"){
            cin>>x;
            check(x);
        }
        else if(cmd=="toggle"){
            cin>>x;
            toggle(x);
        }
        else if(cmd=="all"){
            all();
        }
        else if(cmd=="empty"){
            empty();
        }
    }
    return 0;
}
