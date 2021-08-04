#include<iostream>
#include<string.h>
#include<stack>
#define inf 0x3f3f3f3f
using namespace std;
int path[1010],dis[1010],vis[1010],e[1010][1010];
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
            if(!vis[v]&&e[u][v]!=inf&&dis[u]+e[u][v]<dis[v]){
                path[v]=u;
                dis[v]=dis[u]+e[u][v];
            }
        }
    }
}
void print(int start,int dest){
    stack<int> s;
    while(path[dest]!=start){
        s.push(dest);
        dest=path[dest];
    }
    s.push(dest);
    s.push(start);
    while(!s.empty()){
        printf("%d ",s.top());
        s.pop();
    }
}
int main(){
    cin>>n>>m;
    memset(path,-1,sizeof(path));
    memset(e,inf,sizeof(e));
    memset(dis,inf,sizeof(dis));
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        e[u][v]=w;//   有向图
        //e[v][u]=w    无向图
    }
    dijkstra(0,n);
    print(0,5);
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