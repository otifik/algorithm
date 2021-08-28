//测试点2没过原因：没有将num数组重置
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int num[4];
int main(){
    cin>>n;
    if(n==6174){
        printf("7641 - 1467 = 6174");
    }
    while(n!=6174){
        int cnt=0;
        while(n){
            num[cnt++]=n%10;
            n/=10;
        }
        sort(num,num+4);
        int front=0;
        for(int i=3;i>=0;i--){
            front = front*10+num[i];
        }
        int behind = 0;
        for(int i=0;i<4;i++){
            behind = behind*10+num[i];
        }
        n = front-behind;
        printf("%04d - %04d = %04d\n",front,behind,n);
        for(int i=0;i<4;i++){
            num[i]=0;
        }
        if(!n){
            break;
        }
    }
    return 0;
}