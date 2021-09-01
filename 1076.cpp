//图的遍历，bfs
#include<iostream>
#include<vector>
#include<queue>
#define inf 0x3f3f3f3f
using namespace std;
int n,l,m,temp,k,queryId;
vector<vector<int>> vec;
struct node {
    int id;
    int layer;
};
int bfs(node queryNode){
    bool vis[1010]={false};
    queue<node> que;
    que.push(queryNode);
    vis[queryNode.id]=true;
    int cnt=0;
    while(!que.empty()){
        node front = que.front();
        que.pop();
        int id = front.id;
        for(int i=0;i<vec[id].size();i++){
            int nextId = vec[id][i];
            if(!vis[nextId]&&front.layer<l){
                node next = {nextId,front.layer+1};
                que.push(next);
                vis[next.id]=true;
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    cin>>n>>l;
    vec.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>temp;
            vec[temp].push_back(i);
        }
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>queryId;
        node queryNode = {queryId,0};
        cout<<bfs(queryNode)<<endl;
    }
    return 0;
}