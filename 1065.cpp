//坑点：判断溢出
#include<iostream>
using namespace std;
int t;
int main(){
    cin>>t;
    for(int i=1;i<=t;i++){
        long long a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        long long sum = a+b;
        if(a>0&&b>0&&sum<0){
            printf("Case #%d: true\n",i);
        }else if(a<0&&b<0&&sum>=0){
            printf("Case #%d: false\n",i);
        }else if(sum>c){
            printf("Case #%d: true\n",i);
        }else {
            printf("Case #%d: false\n",i);
        }
    }
}