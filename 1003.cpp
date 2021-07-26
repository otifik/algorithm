#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define inf 0x3f3f3f3f
int n,m,c1,c2;
//dis[i]表示从出发点到i结点最短路径的路径长度，num[i]表示从出发点到i结点最短路路径的条数，w[i]表示从出发点到i点救援队的数⽬目之和
int e[510][510],weight[510],dis[510],num[510],w[510];
int vis[510];
int main(){
    cin>>n>>m>>c1>>c2;
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    memset(e,inf,sizeof(e));
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        e[a][b]=e[b][a]=c;
    }
    for(int i=0;i<n;i++){
        e[i][i]=0;
    }
    for(int i=0;i<n;i++){
        dis[i]=e[c1][i];
    }
    num[c1]=1;
    w[c1]=weight[c1];
    for(int i=0;i<n;i++){
        int min=inf,index;
        for(int j=0;j<n-1;j++){
            if(!vis[j]&&dis[j]<min){
                min=dis[j];
                index=j;
            }
        }
        vis[index]=1;
        for(int j=0;j<n;j++){
            if(!vis[j]&&e[index][j]!=inf&&e[index][j]!=0){
                if(e[index][j]+dis[index]<dis[j]){
                    dis[j]=e[index][j]+dis[index];
                    num[j]=num[index];
                    w[j]=w[index]+weight[j];
                }else if(e[index][j]+dis[index]==dis[j]){
                    num[j]+=num[index];
                    if(w[index]+weight[j]>w[j]){
                        w[j]=w[index]+weight[j];
                    }
                }
            }
        }
    }
    cout<<num[c2]<<" "<<w[c2];
}