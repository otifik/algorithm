#include<iostream>
using namespace std;
int maxn=-1;
int n;
int arr[10010];
int main(){
    cin>>n;
    int start = 0,end = n-1,tempIndex = 0, sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum<0){
            sum = 0;
            tempIndex = i+1;
        }else if(sum>maxn){
            start = tempIndex;
            end = i;
            maxn = sum;
        }
    }
    if(maxn<0){
        maxn=0;
    }
    cout<<maxn<<" "<<arr[start]<<" "<<arr[end];
    return 0;
}