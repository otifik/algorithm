/*
本题旨在求去掉一个点后还剩下多少个连通分量
无向图G的极大连通子图称为G的最强连通分量(Connected Component)
*/
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int e[1010][1010];
int vis[1010];
int n,m,k;
int cnt;
void dfs(int start){
    vis[start]=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]&&e[start][i]==1){
            dfs(i);
        }
    }
}
int main(){
    cin>>n>>m>>k;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        e[u][v]=1;
        e[v][u]=1;
    }
    int lost;
    for(int i=0;i<k;i++){
        cnt=0;
        cin>>lost;
        memset(vis,0,sizeof(vis));
        vis[lost]=true;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i);
            }
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}