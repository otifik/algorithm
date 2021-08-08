#include<iostream>
#include<algorithm>
using namespace std;
struct node {
    string id;
    string name;
    int score;
}stu[100005];
int n,c;
bool cmp1(node a,node b){
    return a.id<b.id;
}
bool cmp2(node a,node b){
    if(a.name!=b.name){
        return a.name<b.name;
    }else {
        return a.id<b.id;
    }
}
bool cmp3(node a,node b){
    if(a.score!=b.score){
        return a.score<b.score;
    }else {
        return a.id<b.id;
    }
}
int main(){
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>stu[i].id>>stu[i].name>>stu[i].score;
    }
    if(c==1){
        sort(stu,stu+n,cmp1);
    }else if(c==2){
        sort(stu,stu+n,cmp2);
    }else if(c==3){
        sort(stu,stu+n,cmp3);
    }
    for(int i=0;i<n;i++){
        cout<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
    }
    return 0;
}