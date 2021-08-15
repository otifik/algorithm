//排序，小启发，不要停留在下面一步踌躇不前，要往前想，排序之前就可以完成的，为什么非要放到后面排序
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> vec[110];
vector<int> tempPath;
vector<vector<int>> path;
int n,m,goalWeight;
int w[110],vis[110];
void dfs(int node,int weight,int nowWeight){
    tempPath.push_back(nowWeight);
    if(weight==goalWeight&&vec[node].empty()){
        path.push_back(tempPath);
    }else {
        for(int i=0;i<vec[node].size();i++){
            dfs(vec[node][i],weight+w[vec[node][i]],w[vec[node][i]]);
        }
    }
    tempPath.pop_back();
}
bool cmp(int a,int b){
    return w[a]>w[b];
}
int main(){
    cin>>n>>m>>goalWeight;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    int root,num,id;
    for(int i=0;i<m;i++){
        cin>>root>>num;
        for(int j=0;j<num;j++){
            cin>>id;
            vec[root].push_back(id);
        }
        sort(vec[root].begin(),vec[root].end(),cmp);
    }
    dfs(0,w[0],w[0]);
    for(int i=0;i<path.size();i++){
        for(int j=0;j<path[i].size();j++){
            if(j){
                cout<<" ";
            }
            cout<<path[i][j];
        }
        cout<<endl;
    }
    return 0;
}