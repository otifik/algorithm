#include<iostream>
#include<algorithm>
#include<queue>
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
int num;
struct node {
    int time;
    int processTime;
}customer[10010];
int h,minute,s;
bool cmp (struct node a,struct node b){
    return a.time<b.time;
}
int waitTime,sum;
queue<struct node> que[110];
queue<struct node> cust;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d:%d:%d",&h,&minute,&s);
        customer[i].time=h*3600+minute*60+s;
        cin>>customer[i].processTime;
    }
    sort(customer,customer+n,cmp);
    for(int i=0;i<n;i++){
        if(customer[i].time<=61200){
            cust.push(customer[i]);
            num++;
        }
    }
    for(int i=0;i<m;i++){
        if(!cust.empty()){
            struct node temp = cust.front();
            cust.pop();
            que[i].push(temp);
        }
    }
    while(!cust.empty()){
        
    }
    return 0;
}
//处理时间大于17.



07:55:00 16
07:59:59 15
08:00:00 30
08:00:02 2
08:01:00 60
08:03:00 10
17:00:01 2



