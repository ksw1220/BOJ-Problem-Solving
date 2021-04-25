#include<iostream>
#include<vector>
using namespace std;

bool chk(int x, int y, int size,vector<vector<int>> &v){
    int pivot=v[x][y];
    bool re=true;
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(pivot!=v[i][j]){
                re=false;
                break;
            }
        }
    }
    return re;
}
void split(int x, int y, int size, vector<vector<int>> &v, int &white, int &blue){
    bool isPaper=chk(x,y,size,v);
    int pivot=v[x][y];
    if(isPaper){
        if(pivot==0) white++;
        else blue++;
    }
    else{
        split(x, y, size/2, v, white, blue);
        split(x, y+size/2, size/2, v, white, blue);
        split(x+size/2, y, size/2, v, white, blue);
        split(x+size/2, y+size/2, size/2, v, white, blue);
    }
}
int main(){
    vector<vector<int>> v(128,vector<int>(128,0));
    int N;
    cin>> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&v[i][j]);
        }
    }
    int w=0,b=0;
    split(0,0,N,v,w,b);
    printf("%d\n%d\n",w,b);
    return 0;
}