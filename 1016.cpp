/*
整体思想，计算费用的时候，不要一分钟一分钟的算，用00:00:00到结束时间的总钱数减去
00:00:00到开始时间的总钱数
重在思想，实现不难
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int rate[25];
struct node {
    string name;
    int month;
    int day;
    int hour;
    int minute;
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
double billFromZero(node call,int* rate){
    double total = rate[call.hour] * call.minute+rate[24]*60*call.day;
    for(int i=0;i<call.hour;i++){
        total+=rate[i]*60;
    }
    return total/100;
}
int main(){
    for(int i=0;i<24;i++){
        cin>>rate[i];
        rate[24]+=rate[i];
    }
    cin>>n;
    string s;
    int month,day,hour,minute;
    for(int i=0;i<n;i++){
        cin>>user[i].name;
        scanf("%d:%d:%d:%d",&month,&day,&hour,&minute);
        user[i].month = month;
        user[i].day=day;
        user[i].hour=hour;
        user[i].minute=minute;
        user[i].time = day*24*60+hour*60+minute;
        cin>>s;
        if(s=="on-line"){
            user[i].state=1;
        }else {
            user[i].state=0;
        }
    }
    sort(user,user+n,cmp);
    map<string,vector<node>> custom;
    for(int i=1;i<n;i++){
        if(user[i].name==user[i-1].name&&user[i-1].state==1&&user[i].state==0){
            custom[user[i-1].name].push_back(user[i-1]);
            custom[user[i].name].push_back(user[i]);
        }
    }
    for(auto it:custom){
        vector<node> temp = it.second;
        cout<<it.first;
        printf(" %02d\n",temp[0].month);
        double total = 0.0;
        for(int i=1;i<temp.size();i+=2){
            double t = billFromZero(temp[i],rate)-billFromZero(temp[i-1],rate);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].day,temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour,temp[i].minute, temp[i].time - temp[i - 1].time, t);
            total+=t;
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}

