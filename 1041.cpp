#include<iostream>
using namespace std;
int vis[10010];
int num[100010];
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        vis[num[i]]++;
    }
    for(int i=0;i<n;i++){
        if(vis[num[i]]==1){
            cout<<num[i];
            return 0;
        }
    }
    cout<<"None";
    return 0;
}