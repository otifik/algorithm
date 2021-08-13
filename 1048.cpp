#include<iostream>
using namespace std;
int n,m,temp;
int coin[520];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>temp;
        coin[temp]++;
    }
    for(int i=0;i<520;i++){
        if(coin[i]){
            coin[i]--;
            if(m>i&&coin[m-i]){
                cout<<i<<" "<<m-i;
                return 0;
            }
            coin[i]++;
        }
    }
    cout<<"No Solution";
    return 0;
}
/*
//伞兵代码
#include<iostream>
#include<algorithm>
using namespace std;
int coins[100005];
int n,payment;
int findTemp(int num){
    int left = 0,right = n-1;
    while(left<right){
        int mid=(left+right)/2;
        if(coins[mid]>=num){
            right = mid;
        }else {
            left = mid+1;
        }
    }
    if(coins[right]==num){
        return 1;
    }else {
        return 0;
    }
}
int main(){
    cin>>n>>payment;
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    sort(coins,coins+n);
    int bound = payment/2;
    for(int i=0;i<n;i++){
        if(coins[i]<bound){
            int temp = payment-coins[i];
            if(findTemp(temp)){
                cout<<coins[i]<<" "<<temp;
                return 0;
            }
        }else if(coins[i]==bound) {
            for(int j=i+1;j<n;j++){
                if(coins[i]+coins[j]==payment){
                    cout<<coins[i]<<" "<<coins[j];
                    return 0;
                }else if(coins[i]+coins[j]>payment){
                    break;
                }
            }
        }else {
            break;
        }
    }
    cout<<"No Solution";
    return 0;
}
*/