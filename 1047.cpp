//坑点：用cout容易超时，string换成char数组
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,k;
vector<int> course[2510];
string name[40010];
bool cmp(int a,int b){
    return name[a]<name[b];
}
int main(){
    std::ios::sync_with_stdio(false);
    cin>>n>>k;
    int c,id;
    for(int i=0;i<n;i++){
        cin>>name[i]>>c;
        for(int j=0;j<c;j++){
            cin>>id;
            course[id].push_back(i);
        }
    }
    for(int i=1;i<=k;i++){
        cout<<i<<" "<<course[i].size()<<endl;
        sort(course[i].begin(),course[i].end(),cmp);
        for(int j=0;j<course[i].size();j++){
            cout<<name[course[i][j]]<<endl;
        }
    }
    return 0;
}