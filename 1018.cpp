/*题目大意：pbmc是一个共享单车调度站，可以发出或者回收车辆，我们现在要做的
就是从pbmc到有问题的站点，先找出最短路径，再找出需要调度的最少车辆
*/
/*
只能沿着最短路径的方向收集多余自行车，分给后面的节点；后面节点多出来的不能填到前面去，只能计入回收总量。

例如路径上自行车数为5->0->10，并不能把最后一个节点上挪5个给中间的，需要送出5个，并回收5个。

所以总需求量不能用Cmax / 2 * 节点数 - 现有数来计算。

否则测试点5、7均无法通过。
*/
#include<iostream>
#include<vector>
#include<string.h>
#include<math.h>
#define inf 0x3f3f3f3f
using namespace std;
int c,n,s,m;//c为最大承载量，n为站点总数，s为事故站点，m为边
int dis[1010],e[1010][1010],vis[1010],point[1010];
vector<int> pre[1010];
void dijkstra(int start,int n){
    dis[start]=0;
    for(int i=0;i<=n;i++){
        int u=-1,min=inf;
        for(int j=0;j<=n;j++){
            if(!vis[j]&&dis[j]<min){
                min=dis[j];
                u=j;
            }
        }
        if(u==-1){
            break;
        }
        vis[u]=1;
        for(int v=0;v<=n;v++){
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
int minneed=inf;
int minback=inf;
vector<int> path;
vector<int> tempPath;
void dfs(int start,int v){
    tempPath.push_back(v);
    if(v==start){
        int need=0,back=0;
        for(int i=tempPath.size()-1;i>=0;i--){
            int id = tempPath[i];
            if(point[id]>0){
                back+=point[id];
            }else {
                if(back>(0-point[id])){
                    back+=point[id];
                }else {
                    need+=((0-point[id])-back);
                    back=0;
                }
            }
        }
        if(need<minneed){
            minneed=need;
            minback=back;
            path=tempPath;
        }else if(need==minneed&&back<minback){
            minback=back;
            path=tempPath;
        }
    }
    for(int i=0;i<pre[v].size();i++){
        dfs(start,pre[v][i]);
    }
    tempPath.pop_back();
}
int main(){
    cin>>c>>n>>s>>m;
    memset(e,inf,sizeof(e));
    memset(dis,inf,sizeof(dis));
    for(int i=1;i<=n;i++){
        cin>>point[i];
        point[i]=point[i]-c/2;
    }
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        e[u][v]=w;
        e[v][u]=w;
    }
    dijkstra(0,n);
    dfs(0,s);
    //TODO
    cout<<minneed<<" ";
    for(int i=path.size()-1;i>=0;i--){
        if(i!=path.size()-1){
            cout<<"->";
        }
        cout<<path[i];
    }
    cout<<" "<<minback;
    return 0;
}