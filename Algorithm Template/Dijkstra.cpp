#include<iostream>
#include<string.h>
#define inf 0x3f3f3f3f
#define maxn 1010
using namespace std;
int e[maxn][maxn],vis[maxn],dis[maxn];
int n,m,start,dest;
int main(){
    //输入，略
    memset(e,inf,sizeof(e));
    memset(dis,inf,sizeof(dis));
    dis[start]=0;
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
            if(!vis[v]&&e[u][v]!=inf&&dis[u]+e[u][v]<dis[v]){
                dis[v]=dis[u]+e[u][v];
            }
        }
    }
    return 0;
}