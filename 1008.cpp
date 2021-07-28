#include<iostream>
using namespace std;
int n;
int arr[110];
int sum;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        if(arr[i]>arr[i-1]){
            sum+=(arr[i]-arr[i-1])*6+5;
        }else {
            sum+=(arr[i-1]-arr[i])*4+5;
        }
    }
    cout<<sum;
    return 0;
}