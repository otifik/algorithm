#include<iostream>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
double capacity,dis,disPerUnit;
int n;
struct node {
    double price;
    double dis;
}station[520];
bool cmp(node a,node b){
    return a.dis<b.dis;
}
int main(){
    cin>>capacity>>dis>>disPerUnit>>n;
    station[0].dis=dis;
    station[0].price=0.0;
    for(int i=1;i<=n;i++){
        cin>>station[i].price>>station[i].dis;
    }
    sort(station,station+n+1,cmp);
    double nowdis=0.0,maxdis=0.0,nowprice=0.0,totalprice=0.0,leftdis=0.0;
    if(station[0].dis!=0){
        cout<<"The maximum travel distance = 0.00";
        return 0;
    }else {
        nowprice = station[0].price;
    }
    while(nowdis<dis){
        maxdis = nowdis+capacity*disPerUnit;//最远能到达的距离
        double minPriceDis = 0,minPrice = inf;//如果找不到比当前更低价格的加油站，那么就在油价高的里面找低的加油站，minPriceDis就是那个加油站离起点的距离，minPrice就是油价
        int flag=0;
        for(int i=1;i<=n&&station[i].dis<=maxdis;i++){
            if(station[i].dis<=nowdis) continue;//之前找过的就不用再找了
            if(station[i].price<nowprice){//找到小的直接去
                totalprice+=(station[i].dis - nowdis - leftdis)*nowprice/disPerUnit;
                leftdis=0.0;
                nowprice = station[i].price;
                nowdis = station[i].dis;
                flag=1;
                continue;
            }//找到了比当前油价更低的加油站，直接过去，下面的就不用执行
            if(station[i].price<minPrice){
                minPrice = station[i].price;
                minPriceDis = station[i].dis;
            }//没找到的话，尽可能在油价高的里面找油价低的
        }
        if(flag==0&&minPrice!=inf){
            totalprice+=(nowprice*(capacity - leftdis/disPerUnit));
            leftdis = capacity*disPerUnit - (minPriceDis-nowdis);//此处剩余的距离就是油箱拉满后的总距离减去上一次油箱拉满到相对便宜的加油站的距离
            nowprice = minPrice;
            nowdis = minPriceDis;
        }//因为我能到达的地方的油价都比现在的贵，那么我只能把油箱装满现在价格相对较低的油，相当于把油箱拉满，但是要注意油箱里面可能有剩余的油
        if(flag==0&&minPrice==inf){
            nowdis+=capacity*disPerUnit;
            printf("The maximum travel distance = %.2f",nowdis);
            return 0;
        }
    }
    printf("%.2f",totalprice);
    return 0;
}