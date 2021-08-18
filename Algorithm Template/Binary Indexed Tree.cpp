#include<iostream>
using namespace std;
const int maxn = 10010;
int n;
int c[maxn];
int lowbit(int t){
    return t&(-t);
}
int update(int x,int delta){
    for(int i=x;i<=n;i+=lowbit(i)){
        c[i]+=delta;
    }
}
int getSum(int x){
    int sum=0;
    for(int i=x;i>=1;i-=lowbit(i)){
        sum+=c[i];
    }
    return sum;
}
int main(){
    int temp;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>temp;
        update(i,temp);
    }
    //logic operation
    return 0;
}