#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main(){
    string A,B;
    vector<int> a,b;    
    stack<int> answer;    
    a.assign(10002,0);
    b.assign(10002,0);
    
    cin>>A>>B;

    int idx=0;
    int a_len=A.length(),b_len=B.length();
    for(int i=a_len-1;i>=0;i--){
    
        a[idx++]=A[i]-'0';
    }

    idx=0;
    for(int i=b_len-1;i>=0;i--){
        b[idx++]=B[i]-'0';
    }
    if(a_len<b_len)a_len=b_len;
    idx=0;
    int tmp,carry=0;

    while(1){
        tmp=a[idx]+b[idx]+carry;
        if(tmp==0&&idx>=a_len)
            break;
        if(tmp>=10){
            tmp-=10;
            carry=1;
        }
        else 
            carry=0;
        idx++;
        answer.push(tmp);
    }
    while(!answer.empty()){
        printf("%d",answer.top());
        answer.pop();
    }
    return 0;
}