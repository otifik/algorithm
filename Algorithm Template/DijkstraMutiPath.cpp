#include<iostream>
#include<string.h>
#include<vector>
#define inf 0x3f3f3f3f
using namespace std;
vector<int> pre[1010];
int dis[1010],vis[1010],e[1010][1010];
int n,m;
void dijkstra(int start,int n){
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
            if(!vis[v]&&e[u][v]!=inf){
                if(dis[u]+e[u][v]<dis[v]){
                    dis[v]=dis[u]+e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dis[u]+e[u][v]==dis[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
int best;//存放最优值
vector<int> path;//最优路径
vector<int> tempPath;//临时路径
void dfs(int start,int v){
    tempPath.push_back(v);
    if(v==start){
        //TODO:计算value
        //TODO:计算出来的value和res进行比较，如果更优，就更新最优值和最优路径
    }else {
        for(int i=0;i<pre[v].size();i++){
            dfs(start,pre[v][i]);
        }
    }
    tempPath.pop_back();
}
int main(){
    cin>>n>>m;
    memset(e,inf,sizeof(e));
    memset(dis,inf,sizeof(dis));
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        e[u][v]=w;//   有向图
        //e[v][u]=w    无向图
    }
    dijkstra(0,n);
    //dfs
    return 0;
}

/*测试用例
6         
8
0 1 10
0 3 30 
1 2 50
1 4 100
2 4 5
3 2 20
3 4 60
4 5 10
*/