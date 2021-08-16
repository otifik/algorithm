#include<iostream>
#include<map>
using namespace std;
map<int,int> pic;
int m,n;
int dig;
int maxn=-1;
int domain=0;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>dig;
            pic[dig]++;
        }
    }
    for(auto it=pic.begin();it!=pic.end();it++){
        if(it->second>maxn){
            maxn=it->second;
            domain=it->first;
        }
    }
    cout<<domain;
    return 0;
}