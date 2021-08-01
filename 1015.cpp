//判断n和n在radix进制下反转的数字在十进制下都是素数
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<string>
using namespace std;
int n,r;
bool prime(int a){
    if(a==1){
        return false;
    }
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}
int a[10];
int main(){
    while(cin>>n){
        if(n<0){
            break;
        }
        cin>>r;
        int temp=n;
        int cnt=0;
        while(temp){
            a[cnt++]=temp%r;
            temp/=r;
        }
        int reverseNum=0;
        for(int i=0;i<cnt;i++){
            reverseNum=r*reverseNum+a[i];
        }
        cout<<reverseNum<<endl;
        if(prime(n)&&prime(reverseNum)){
            cout<<"Yes"<<endl;
        }else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}