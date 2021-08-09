//坑点：输出的顺序要按照字母顺序来排列
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
map<string,int> sToi;
map<int,string> iTos;
int id=0;
int tran(string s){
    if(sToi[s]==0){
        sToi[s]=++id;
        return id;
    }else {
        return sToi[s];
    }
}
struct node {
    int head;
    int num;
}tempnode;
bool cmp(node a,node b){
    return iTos[a.head]<iTos[b.head];
}
vector<node> total;
int n,k;
int weight[2021],e[2021][2021],vis[2021];
int cnt;
int maxWeight;
int maxIndex;
int totalWeight;
int cntPeople;
void dfs(int start){
    cntPeople++;
    if(weight[start]>maxWeight){
        maxWeight=weight[start];
        maxIndex=start;
    }
    totalWeight+=weight[start];
    vis[start]=1;
    for(auto it=iTos.begin();it!=iTos.end();it++){
        if(!vis[it->first]&&e[start][it->first]){
            dfs(it->first);
        }
    }
}
int main(){
    cin>>n>>k;
    string s1,s2;
    int w;
    for(int i=0;i<n;i++){
        cin>>s1>>s2>>w;
        int u=tran(s1);
        int v=tran(s2);
        iTos[u]=s1;
        iTos[v]=s2;
        weight[u]+=w;
        weight[v]+=w;
        e[u][v]+=w;
        e[v][u]+=w;
    }
    for(auto it=iTos.begin();it!=iTos.end();it++){
        maxWeight=0,maxIndex=0,totalWeight=0,cntPeople=0;
        if(!vis[it->first]){
            dfs(it->first);
            totalWeight/=2;
            if(totalWeight>k&&cntPeople>2){
                cnt++;
                tempnode.head=maxIndex;
                tempnode.num=cntPeople;
                total.push_back(tempnode);
            }
        }
    }
    cout<<cnt<<endl;
    sort(total.begin(),total.end(),cmp);
    for(int i=0;i<total.size();i++){
        cout<<iTos[total[i].head]<<" "<<total[i].num<<endl;
    }
    return 0;
}