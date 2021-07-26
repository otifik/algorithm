#include<iostream>
#include<string.h>
using namespace std;
#define inf 0x3f3f3f3f
int n,m,c1,c2;
int num[1010],e[1010][1010],weight[1010],w[1010],dis[1010],vis[1010];
int main(){
    cin>>n>>m>>c1>>c2;
    memset(e,inf,sizeof(e));
    memset(dis,inf,sizeof(dis));
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u][v]=e[v][u]=w;
    }
    dis[c1]=0;
    num[c1]=1;
    w[c1]=weight[c1];
    for(int i=0;i<n;i++){
        int u=-1,min=inf;
        for(int j=0;j<n;j++){
            if(!vis[j]&&dis[j]<min){
                u=j;
                min=dis[j];
            }
        }
        if(u==-1){
            break;
        }
        vis[u]=1;
        for(int v=0;v<n;v++){
            if(!vis[v]&&e[u][v]!=inf){
                if(dis[u]+e[u][v]<dis[v]){
                    num[v]=num[u];
                    w[v]=w[u]+weight[v];
                    dis[v]=dis[u]+e[u][v];
                }else if(dis[u]+e[u][v]==dis[v]){
                    num[v]+=num[u];
                    if(w[u]+weight[v]>w[v]){
                        w[v]=w[u]+weight[v];
                    }
                }
            }
        }
    }
    cout<<num[c2]<<" "<<w[c2];
    return 0;
}