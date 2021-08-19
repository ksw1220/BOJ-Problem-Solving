#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v(3,0);

    scanf("%d %d %d",&v[0],&v[1],&v[2]);

    sort(v.begin(),v.end());

    
    printf("%d %d %d\n",v[0],v[1],v[2]);
    return 0;
}
