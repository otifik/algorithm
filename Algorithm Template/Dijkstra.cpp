#include<iostream>
#include<string.h>
using namespace std;
#define inf 0x3f3f3f3f
int map[1010][1010];//这是一个二维模拟数组，map[i][j]对应从i到j的边权（注意不要和边长混淆概念）
int vis[1010],dis[1010];//vis[i]代表i到某一点是否是确定的最短路径，dis[i]是确定的最短路径的值
int n,m;//n代表有多少点，m代表有多少边
int start;//代表起点
//本模板点下标从1到n
int main(){
    cin>>n>>m;
    //初始化很重要，不要忘记
    memset(map,inf,sizeof(map));
    for(int i=1;i<=n;i++){
        map[i][i]=0;
    }
    //读入图
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map[u][v]=w;
        map[v][u]=w;
    }
    /*以下为Dijkstra实现（可抽取为一个函数）*/
    //vis数组一开始就是定义在main函数外，所以不需要memset，本身就全是0
    //接下来先初始化dis数组
    cin>>start;
    for(int i=1;i<=n;i++){
        dis[i]=map[start][i];
    }
    vis[start]=1;//因为是初始点，所以直接标记为访问过
    for(int i=1;i<n;i++){//为了确保每个点到起始点都是最短路径，就要进行n-1次的迭代，使得vis数组从1到n都是1，即都访问过
        //下面的操作是找出未确定最短路径的点中离初始点最近的一个点
        int min=inf,index;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dis[j]<min){
                min=dis[j];
                index=j;
            }
        }
        vis[index]=1;//表明已经确定最短路径
        //下面的操作就是逐个更新最段路
        for(int j=1;j<=n;j++){
            if(map[index][j]+dis[index]<dis[j]){
                dis[j]=map[index][j]+dis[index];
            }
        }
    }
    /*至此，Dijkstra实现结束*/
    //这边就进行一下简单的输出
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}

#include<iostream>
#include<string.h>
using namespace std;
#define inf 0x3f3f3f3f
int map[1010][1010];//这是一个二维模拟数组，map[i][j]对应从i到j的边权（注意不要和边长混淆概念）
int vis[1010],dis[1010];//vis[i]代表i到某一点是否是确定的最短路径，dis[i]是确定的最短路径的值
int n,m;//n代表有多少点，m代表有多少边
int start;//代表起点
//本模板点下标从1到n
int main(){
    cin>>n>>m;
    //初始化很重要，不要忘记
    memset(map,inf,sizeof(map));
    //读入图
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map[u][v]=w;
        map[v][u]=w;
    }
    /*以下为Dijkstra实现（可抽取为一个函数）*/
    //vis数组一开始就是定义在main函数外，所以不需要memset，本身就全是0
    cin>>start;
    memset(dis,inf,sizeof(dis));
    dis[start]=0;
    for(int i=1;i<=n;i++){//为了确保每个点到起始点都是最短路径，就要进行n次的迭代，使得vis数组从1到n都是1，即都访问过
        //下面的操作是找出未确定最短路径的点中离初始点最近的一个点
        int min=inf,index=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dis[j]<min){
                min=dis[j];
                index=j;
            }
        }
        if(index==-1){
            break;
        }
        vis[index]=1;//表明已经确定最短路径
        //下面的操作就是逐个更新最段路
        for(int j=1;j<=n;j++){
            if(map[index][j]+dis[index]<dis[j]){
                dis[j]=map[index][j]+dis[index];
            }
        }
    }
    /*至此，Dijkstra实现结束*/
    //这边就进行一下简单的输出
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}