#include<iostream>
#include<map>
#include<set>
using namespace std;
int n,k;
int id,num;
map<string,set<int>> stu;
string name;
int main(){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>id>>num;
        for(int j=0;j<num;j++){
            cin>>name;
            stu[name].insert(id);
        }
    }
    for(int i=0;i<n;i++){
        cin>>name;
        int total = stu[name].size();
        cout<<name<<" "<<total;
        for(auto it = stu[name].begin();it!=stu[name].end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
    }
    return 0;
}