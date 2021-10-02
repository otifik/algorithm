#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int maxn = 0x3f3f3f3f;
map<string,int> name;
map<int,string> id;
int happiness[210];
int n,m;
int cost[210][210];
int vis[210];
string placeName;
int planNumber,maxHappiness,avgHappiness;
int minCost=maxn;
vector<int> plan;
vector<int> bestPlan;
void dfs(int a){
    if(a==name["ROM"]){
        int c = 0;
        for(int i=0;i<plan.size()-1;i++){
            c+=cost[plan[i]][plan[i+1]];
        }
        int h=0;
        for(int i=1;i<plan.size();i++){
            h+=happiness[plan[i]];
        }
        if(c<minCost){
            planNumber=1;
            minCost=c;
            maxHappiness=h;
            avgHappiness=h/(plan.size()-1);
            bestPlan=plan;
        }else if(c==minCost){
            planNumber++;
            if(h>maxHappiness){
                bestPlan=plan;
                maxHappiness=h;
                avgHappiness=h/(plan.size()-1);
            }else if(h==maxHappiness){
                if(h/(plan.size()-1)>avgHappiness){
                    bestPlan=plan;
                    avgHappiness=h/(plan.size()-1);
                }
            }
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(cost[a][i]!=0&&vis[i]==0){
            plan.push_back(i);
            vis[i]=1;
            dfs(i);
            vis[i]=0;
            plan.pop_back();
        }
    }
}
int main(){
    cin>>n>>m;
    cin>>placeName;
    name[placeName]=1;
    id[1]=placeName;
    for(int i=2;i<=n;i++){
        cin>>placeName;
        name[placeName]=i;
        cin>>happiness[i];
        id[i]=placeName;
    }
    string s1,s2;
    int money;
    for(int i=0;i<m;i++){
        cin>>s1>>s2;
        cin>>money;
        cost[name[s1]][name[s2]]=money;
        cost[name[s2]][name[s1]]=money;
    }
    plan.push_back(1);
    vis[1]=1;
    dfs(1);
    cout<<planNumber<<" "<<minCost<<" "<<maxHappiness<<" "<<avgHappiness<<endl;
    for(int i=0;i<bestPlan.size();i++){
        if(i){
            cout<<"->";
        }
        cout<<id[bestPlan[i]];
    }
    return 0;
}