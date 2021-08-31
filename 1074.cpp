//翻转链表只是next变，但是它本身的地址是不变的
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100010;
int data[maxn];
int list[maxn];
int start,n,k;
int main(){
    int next[maxn];
    cin>>start>>n>>k;
    int temp,cnt=0;
    for(int i=0;i<n;i++){
        cin>>temp;
        cin>>data[temp]>>next[temp];
    }
    while(start!=-1){
        list[cnt++]=start;
        start=next[start];
    }
    for(int i=0;i<(cnt-cnt%k);i+=k){
        reverse(list+i,list+i+k);
    }
    for(int i=0;i<cnt-1;i++){
        printf("%05d %0d %05d\n",list[i],data[list[i]],list[i+1]);
    }
    printf("%05d %d -1",list[cnt-1],data[list[cnt-1]]);
    return 0;
}