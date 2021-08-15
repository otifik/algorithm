//https://cloud.tencent.com/developer/article/1660952
#include<iostream>
using namespace std;
int n,ans,radix=1,leftNum,rightNum,now;
int main(){
    cin>>n;
    while(n/radix){
        leftNum = n/(radix*10);
        now = n/radix%10;
        rightNum = n%radix;
        if(now==0){
            ans+=leftNum*radix;
        }else if(now==1){
            ans+=leftNum*radix +rightNum+1;
        }else if(now>1){
            ans+=(leftNum+1)*radix;
        }
        radix*=10;
    }
    cout<<ans;
    return 0;
}