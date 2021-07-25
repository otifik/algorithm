#include<iostream>
using namespace std;
int n,exp;
double map[1010],coe;
int cnt;
int main(){
    cin>>n;
    while(n--){
        cin>>exp>>coe;
        map[exp]+=coe;
    }
    cin>>n;
    while(n--){
        cin>>exp>>coe;
        map[exp]+=coe;
    }
    for(int i=0;i<1010;i++){
        if(map[i]!=0){
            cnt++;
        }
    }
    cout<<cnt;
    for(int i=1000;i>=0;i--){
        if(map[i]!=0){
            printf(" %d %.1f",i,map[i]);
        }
    }
    return 0;
}