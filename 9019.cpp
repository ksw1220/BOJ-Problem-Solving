#include<iostream>
#include<string>
#include<queue>
#include<vector>

#define INF 987654321
using namespace std;

bool chk[10001];
int res[10001][4];
string res_s[4]={"D","S","L","R"};
queue<pair<int,string>> que;
int D(int n){
    return (n*2)%10000;
}
int S(int n){
    return (n+9999)%10000;
}
int L(int n){
    return n/1000+(n*10)%10000;
}
int R(int n){
    return n/10+(n%10)*1000;
}
string solution(int start,int end){
    que.push({start,""});
    chk[start]=true;
    while(!que.empty()){
        int now=que.front().first;
        string acc=que.front().second;
        que.pop();
        if(now==end){
            return acc;     
        }
        for(int i=0;i<4;i++){
            int to=res[now][i];
            if(!chk[to]){
                chk[to]=true;
                que.push({to,acc+res_s[i]});
            }
        }
    }
}
int main(){
    int T,A,B;
    cin>>T;
    for(int i=0;i<10001;i++){
        res[i][0]=D(i);
        res[i][1]=S(i);
        res[i][2]=L(i);
        res[i][3]=R(i);
    }
    while(T--){
        scanf("%d %d",&A,&B);
        while(!que.empty())que.pop();
        for(int i=0;i<10001;i++)chk[i]=false;

        string answer=solution(A,B);
        cout<<answer<<endl;
    }
    return 0;
}