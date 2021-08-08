#include<iostream>
#include<vector>
#include<string.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,start,dest,cost;
int vis[550],dis[550],dist[550][550],costs[550][550];
vector<int> pre[550];
void dijkstra(int start){
    dis[start]=0;
    for(int i=0;i<n;i++){
        int u=-1,min=inf;
        for(int j=0;j<n;j++){
            if(!vis[j]&&dis[j]<min){
                min=dis[j];
                u=j;
            }
        }
        if(u==-1){
            break;
        }
        vis[u]=1;
        for(int v=0;v<n;v++){
            if(!vis[v]&&dist[u][v]!=inf){
                if(dis[u]+dist[u][v]<dis[v]){
                    dis[v]=dis[u]+dist[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dis[u]+dist[u][v]==dis[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
vector<int> tempPath;
vector<int> path;
int minValue=inf;
int totalDistance;
void dfs(int start,int v){
    tempPath.push_back(v);
    if(v==start){
        int value=0;
        int tempDistance=0;
        for(int i=0;i<tempPath.size()-1;i++){
            value+=costs[tempPath[i]][tempPath[i+1]];
            tempDistance+=dist[tempPath[i]][tempPath[i+1]];
        }
        if(value<minValue){
            minValue=value;
            path=tempPath;
            totalDistance=tempDistance;
        }
    }else {
        for(int i=0;i<pre[v].size();i++){
            dfs(start,pre[v][i]);
        }
    }
    tempPath.pop_back();
}
int main(){
    memset(dis,inf,sizeof(dis));
    memset(dist,inf,sizeof(dist));
    cin>>n>>m>>start>>dest;
    int u,v,d,c;
    for(int i=0;i<m;i++){
        cin>>u>>v>>d>>c;
        dist[u][v]=d;
        dist[v][u]=d;
        costs[u][v]=c;
        costs[v][u]=c;
    }
    dijkstra(start);
    dfs(start,dest);
    for(int i=path.size()-1;i>=0;i--){
        if(i!=path.size()-1){
            cout<<" ";
        }
        cout<<path[i];
    }
    cout<<" "<<totalDistance<<" "<<minValue;
    return 0;
}