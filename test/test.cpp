#include<iostream>
#include<string.h>
using namespace std;
#define inf 0x3f3f3f3f
int vis[1010],map[1010][1010];
int n,m,start;
int dis[1010];
int main(){
    cin>>n>>m;
    memset(map,inf,sizeof(map));
    for(int i=1;i<=n;i++){
        map[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map[u][v]=w;
        map[v][u]=w;
    }
    cin>>start;
    vis[start]=1;
    for(int i=1;i<=n;i++){
        dis[i]=map[start][i];
    }
    for(int i=1;i<n;i++){
        int min=inf,index;
        for(int j=1;j<=n;j++){
            if(min>dis[j]&&!vis[j]){
                min=dis[j];
                index=j;
            }
        }
        vis[index]=1;
        for(int j=1;j<=n;j++){
            if(dis[index]+map[index][j]<dis[j]){
                dis[j]=dis[index]+map[index][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i];
    }
    return 0;
}