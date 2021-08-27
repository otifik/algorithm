//记录下每个数字所在的位置，遍历一遍所有数字，如果0位置不是0，那么就一直交换，否则找到第一个不是0的进行交换，然后继续遍历
#include<iostream>
using namespace std;
int cnt;
int n;
int a[100010];
int main(){
    cin>>n;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        a[temp]=i;
    }
    for(int i=1;i<n;i++){
        if(i!=a[i]){
            while(a[0]!=0){
                swap(a[0],a[a[0]]);
                cnt++;
            }
            if(i!=a[i]){
                swap(a[0],a[i]);
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}