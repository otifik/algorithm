//坑点：测试点2不过是因为amount也可能是double型
#include<iostream>
#include<algorithm>
using namespace std;
int n,d;
struct node {
    double totalPrice;
    double amount;
    double avgPrice;
}mooncake[1010];
double total[1010];
double a[1010];
bool cmp(node a,node b){
    return a.avgPrice>b.avgPrice;
}
int main(){
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>total[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        mooncake[i].amount=total[i];
        mooncake[i].totalPrice=a[i];
        mooncake[i].avgPrice=mooncake[i].totalPrice/mooncake[i].amount;
    }
    sort(mooncake,mooncake+n,cmp);
    double res=0;
    for(int i=0;i<n;i++){
        if(d>=mooncake[i].amount){
            res+=mooncake[i].totalPrice;
            d-=mooncake[i].amount;
        }else if(d<mooncake[i].amount){
            res+=mooncake[i].avgPrice*d;
            d=0;
        }
        if(d==0){
            break;
        }
    }
    printf("%.2f",res);
    return 0;
}