#include<iostream>
#include<algorithm>
using namespace std;
struct node {
    int id;
    int virtue;
    int talent;
    int sum;
    int w;
}peo[100010];
int n,l,h;
bool cmp(node a,node b){
    if(a.w!=b.w){
        return a.w>b.w;
    }else if(a.sum!=b.sum){
        return a.sum>b.sum;
    }else if(a.virtue!=b.virtue){
        return a.virtue>b.virtue;
    }else {
        return a.id<b.id;
    }
}
int main(){
    cin>>n>>l>>h;
    int id,v,t;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>id>>v>>t;
        int w=0;
        if(v>=h&&t>=h){
            w=4;
        }else if(v>=h&&t>=l&&t<h){
            w=3;
        }else if(v>=t&&v>=l&&v<h&&t>=l&&t<h){
            w=2;
        }else if(v>=l&&t>=l){
            w=1;
        }else {
            continue;
        }
        peo[cnt].id=id;
        peo[cnt].virtue=v;
        peo[cnt].talent=t;
        peo[cnt].sum=v+t;
        peo[cnt].w=w;
        cnt++;
    }
    sort(peo,peo+cnt,cmp);
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        cout<<peo[i].id<<" "<<peo[i].virtue<<" "<<peo[i].talent<<endl;
    }
    return 0;
}