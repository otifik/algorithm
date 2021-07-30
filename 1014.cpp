/*
假设一个银行有n个Windows开放服务。
窗户前面有一条黄线，将等候区分为两部分。 顾客等待的客户的规则是：
1、每个窗口前面的黄线内的空间足以包含M客户的一行。
因此，当所有n行都满了时，所有客户（包括）（包括）（NM + 1）ST的所有客户必须在黄线后面的一行中等待。
2、每位客户都将选择最短的线路在交叉线时等待。
如果有两行或更多行长度一样，客户将始终选择具有最小数字的窗口。
3、第i个客户需要Ti分钟来完成业务
4、假设在上午8:00提供服务。
现在鉴于每个客户的处理时间，您应该告诉客户完成他/她的业务的确切时间。
n，窗口数目；m，黄线内最大承载量；k，顾客数；q，客户查询数量
k个正整数，代表k个用户各自的处理时间
最后一行包含Q正整数，它代表了询问他们可以完成其事务的时间的客户
客户id从1到k
对于每个Q客户，在一行中打印他/她的交易完成的时间，
格式HH：mm，其中hh在[08,17]和mm中在[00，59]中。
请注意，由于银行在17:00之后每天关闭，因为那些无法在17:00之前提供的客户，您必须输出Sorry。
*/
#include<iostream>
#include<algorithm>
#include<queue>
#define inf 0x3f3f3f3f
using namespace std;
struct node {
    int id;
    int processTime;
    int leftTime;
    int endTime;
    int state;
}customer[1010];
queue<node> que[20];
queue<node> custQue;
int dayTime = 480;
int n,m,k,q;
int id;
int flag;
int main(){
    cin>>n>>m>>k>>q;
    for(int i=1;i<=k;i++){
        customer[i].state=0;
        customer[i].id=i;
        cin>>customer[i].leftTime;
        customer[i].processTime=customer[i].leftTime;
        custQue.push(customer[i]);
    }
    //ok初始化
    while(que[n-1].size()!=m&&!custQue.empty()){
        for(int i=0;i<n;i++){
            if(!custQue.empty()){
                struct node cust = custQue.front();
                custQue.pop();
                que[i].push(cust);
            }else {
                break;
            }
        }
    }
    //ok业务逻辑
    while(1){
        flag=0;
        //找出最小值
        int minn=inf;
        for(int i=0;i<n;i++){
            if(!que[i].empty()&&que[i].front().leftTime<minn){
                minn=que[i].front().leftTime;
            }
        }
        dayTime+=minn;
        
        //pop最小值
        for(int i=0;i<n;i++){
            if(!que[i].empty()){
                if(que[i].front().leftTime==minn){
                    customer[que[i].front().id].endTime=dayTime;
                    //逻辑问题
                    que[i].pop();
                }else {
                    que[i].front().leftTime-=minn;
                }
            }
        }

        //补全que队列
        for(int i=0;i<n;i++){
            if(que[i].size()!=m&&!custQue.empty()){
                struct node cust = custQue.front();
                custQue.pop();
                que[i].push(cust);
            }
        }

        //判断是否完成业务
        for(int i=0;i<n;i++){
            if(!que[i].empty()){
                flag=1;
            }
        }
        if(!flag){
            break;
        }
    }

    //绝对没问题
    int hour,minute;
    for(int i=0;i<q;i++){
        cin>>id;
        hour = customer[id].endTime/60;
        minute = customer[id].endTime%60;
        if(customer[id].state){
            printf("Sorry\n");
        }else {
            printf("%02d:%02d\n",hour,minute);
        }
    }
    return 0;
}