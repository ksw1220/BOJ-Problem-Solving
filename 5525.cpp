#include<iostream>
#include<string>
#include<vector>
using namespace std;
void count(int start, int len, string S, vector<int> &v){
    int cnt=0;
    for(int i=start;i<len-2;i+=2){
        if(S[i]=='I'&&S[i+1]=='O'&&S[i+2]=='I'){
            cnt++;
        }
        else {
            if(cnt!=0)
                v.push_back(cnt);
            cnt=0;
        }
    }
     if(cnt!=0)
        v.push_back(cnt);
}
int main(){
    int N,len;
    string S;
    cin>>N>>len;
    cin>>S;
    vector<int> fragment;
    int answer=0;
    
    count(0, len, S, fragment);
    count(1, len, S, fragment);
    for(int i=0;i<fragment.size();i++){
        int tmp=fragment[i];
        if(tmp>=N){
            answer+=tmp-N+1;
        }
    }

    printf("%d",answer);
    return 0;
}