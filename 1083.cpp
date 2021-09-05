#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
    string name,id;
    int grade;
}stu[10010];
int n;
int lowBound,highBound;
vector<node> vec;
bool cmp(node a,node b){
    return a.grade>b.grade;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>stu[i].name>>stu[i].id>>stu[i].grade;
    }
    cin>>lowBound>>highBound;
    for(int i=0;i<n;i++){
        if(stu[i].grade>=lowBound&&stu[i].grade<=highBound){
            vec.push_back(stu[i]);
        }
    }
    if(vec.empty()){
        cout<<"NONE";
        return 0;
    }
    sort(vec.begin(),vec.end(),cmp);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i].name<<" "<<vec[i].id<<endl;
    }
    return 0;
}