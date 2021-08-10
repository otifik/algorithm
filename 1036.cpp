#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
struct node {
    string name;
    char gender;
    string id;
    int grade;
}temp,high,low;
vector<node> male;
vector<node> female;
bool cmp(node a,node b){
    if(a.gender=='M'){
        return a.grade<b.grade;
    }else {
        return a.grade>b.grade;
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp.name>>temp.gender>>temp.id>>temp.grade;
        if(temp.gender=='M'){
            male.push_back(temp);
        }else {
            female.push_back(temp);
        }
    }
    sort(male.begin(),male.end(),cmp);
    sort(female.begin(),female.end(),cmp);
    if(!male.empty()){
        low = male[0];
    }else {
        low.name = "Absent";
    }
    if(!female.empty()){
        high = female[0];
    }else {
        high.name = "Absent";
    }
    cout<<high.name;
    if(high.name=="Absent"){
        cout<<endl;
    }else {
        cout<<" "<<high.id<<endl;
    }
    cout<<low.name;
    if(low.name=="Absent"){
        cout<<endl;
    }else {
        cout<<" "<<low.id<<endl;
    }
    if(high.name=="Absent"||low.name=="Absent"){
        cout<<"NA";
    }else {
        cout<<high.grade-low.grade;
    }
    return 0;
}