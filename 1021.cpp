/*从任意一个节点开始进行深度优先遍历，找到离他最远的所有节点（可能不止一个，记为集合A）；
再从A中任意选一个节点出发进行深度优先遍历，找到离他最远的节点（记为集合B），
最后最深根就是这两个集合的并集。
题解：https://cloud.tencent.com/developer/article/1660898
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int n,maxheight=0;
vector<vector<int>> v;
int vis[10010];
set<int> s;
vector<int> temp;
void dfs(int node,int height){
    if(height>maxheight){
        temp.clear();
        temp.push_back(node);
        maxheight=height;
    }else if(height==maxheight){
        temp.push_back(node);
    }
    vis[node]=1;
    for(int i=0;i<v[node].size();i++){
        if(!vis[v[node][i]]){
            dfs(v[node][i],height+1);
        }
    }
}
int main(){
    cin>>n;
    v.resize(n+1);
    int a,b,cnt=0,s1=0;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,1);
            if(i==1){
                if(temp.size()!=0){
                    s1=temp[0];
                }
                for(int j=0;j<temp.size();j++){
                    s.insert(temp[j]);
                }
            }
            cnt++;
        }
    }
    if(cnt>=2){
        cout<<"Error: "<<cnt<<" components";
    }else {
        temp.clear();
        maxheight=0;
        fill(vis,vis+10010,0);
        dfs(s1,1);
        for(int i=0;i<temp.size();i++){
            s.insert(temp[i]);
        }
        for(auto it=s.begin();it!=s.end();it++){
            cout<<*it<<endl;
        }
    }
}