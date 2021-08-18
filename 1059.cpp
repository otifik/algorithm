#include<iostream>
#include<math.h>
using namespace std;
int n;
int flag=0;
int isPrime(int x){
    if(x==1){
        return 0;
    }
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    cin>>n;
    cout<<n<<"=";
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=2;i<=n;i++){
        if(n==0){
            break;
        }
        if(isPrime(i)&&n%i==0){
            int cnt=0;
            while(n%i==0&&n!=0){
                cnt++;
                n/=i;
            }
            if(!flag){
                if(cnt==1){
                    cout<<i;
                }else {
                    cout<<i<<"^"<<cnt;
                }
                flag=1;
            }else {
                if(cnt==1){
                    cout<<"*"<<i;
                }else {
                    cout<<"*"<<i<<"^"<<cnt;
                }
            }
        }
    }
    return 0;
}