#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#define inf 0x3f3f3f3f
#define maxn 1100
using namespace std;
struct node {
    int num;
    double avg;
    double minDis;
};
vector<node> vec;
bool cmp(node a,node b){
    if(a.minDis!=b.minDis){
        return a.minDis>b.minDis;
    }else if(a.avg!=b.avg) {
        return a.avg<b.avg;
    }else {
        return a.num<b.num;
    }
}
int e[maxn][maxn],vis[maxn],dis[maxn];
int n,m,k,d;
int main(){
    cin>>n>>m>>k>>d;
    memset(e,inf,sizeof(e));
    memset(dis,inf,sizeof(dis));
    string p1,p2;
    int dist;
    for(int i=0;i<k;i++){
        cin>>p1>>p2>>dist;
        int num1,num2;
        if(p1[0]=='G'){
            p1=p1.substr(1);
            num1=stoi(p1)+n;
        }else {
            num1=stoi(p1);
        }
        if(p2[0]=='G'){
            p2=p2.substr(1);
            num2=stoi(p2)+n;
        }else {
            num2=stoi(p2);
        }
        e[num1][num2]=e[num2][num1]=min(dist,e[num1][num2]);
    }
    for(int i=n+1;i<=n+m;i++){
        memset(dis,inf,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[i]=0;
        for(int j=1;j<=n+m;j++){
            int u=-1,min=inf;
            for(int p=1;p<=n+m;p++){
                if(!vis[p]&&dis[p]<min){
                    u=p;
                    min=dis[p];
                }
            }
            if(u==-1){
                break;
            }
            vis[u]=1;
            for(int v=1;v<=n+m;v++){
                if(!vis[v]&&e[u][v]!=inf&&dis[u]+e[u][v]<dis[v]){
                    dis[v]=dis[u]+e[u][v];
                }
            }
        }
        double minDis=inf,avg,sum=0;
        bool flag=false;
        for(int j=1;j<=n;j++){
            if(dis[j]>d){
                flag=true;
                break;
            }
            if(dis[j]<minDis){
                minDis=dis[j];
            }
            sum+=dis[j];
        }
        if(flag){
            continue;
        }else {
            node* temp = new node();
            temp->minDis = minDis;
            temp->avg = sum/n;
            temp->num = i-n;
            vec.push_back(*temp);
        }
//         memset(dis,inf,sizeof(dis));
//         memset(vis,0,sizeof(vis));
    }
    if (vec.empty()){
        printf("No Solution");
    } else{
        sort(vec.begin(),vec.end(),cmp);
        printf("G%d\n%.1f %.1f",vec[0].num,vec[0].minDis,vec[0].avg);
    }
    return 0;
}