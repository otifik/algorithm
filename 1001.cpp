#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;
int a,b;
int res;
int arr[10],cnt;
string s="";
int main(){
    cin>>a>>b;
    res=a+b;
    int absolute=fabs(res);
    if(res!=absolute){
        cout<<"-";
    }
    if(res==0){
        cout<<0;
    }
    while(absolute){
        arr[cnt++]=absolute%10;
        absolute/=10;
    }
    for(int i=0;i<cnt;i++){
        if(i==3||i==6){
            s+=",";
        }
        s+=(arr[i]+'0');
    }
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}