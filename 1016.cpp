#include<iostream>
#include<algorithm>
using namespace std;
int cost[24];
struct node {
    string name;
    int month;
    int time;
    int state;
}user[1010];
int n;
bool cmp(struct node a,struct node b){
    if(a.name!=b.name){
        return a.name<b.name;
    }else {
        return a.time<b.time;
    }
}
int main(){
    for(int i=0;i<24;i++){
        cin>>cost[i];
    }
    cin>>n;
    string s;
    int month,day,hour,minute;
    for(int i=0;i<n;i++){
        cin>>user[i].name;
        scanf("%d:%d:%d:%d",&month,&day,&hour,&minute);
        user[i].month = month;
        user[i].time = day*24*60+hour*60+minute;
        cin>>s;
        if(s=="on-line"){
            user[i].state=1;
        }else {
            user[i].state=0;
        }
    }
    sort(user,user+n,cmp);
    for(int i=0;i<n;i++){
        
    }
    return 0;
}