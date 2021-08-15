//坑点：有的结点根本不不在链表中
#include<iostream>
#include<algorithm>
using namespace std;
struct node {
    int data;
    int add,next;
    bool flag;
}list[100000];
int n,head;
int cnt;
bool cmp(node a,node b){
    return !a.flag||!b.flag?a.flag>b.flag:a.data<b.data;
}
int main(){
    cin>>n>>head;
    int a,d,next;
    for(int i=0;i<n;i++){
        cin>>a>>d>>next;
        list[a].add=a;
        list[a].data=d;
        list[a].next=next;
        list[a].flag=false;
    }
    for(int i=head;i!=-1;i=list[i].next){
        list[i].flag=true;
        cnt++;
    }
    if(cnt==0){
        cout<<"0 -1";
        return 0;
    }else {
        sort(list,list+100000,cmp);
        printf("%d %05d\n",cnt,list[0].add);
        for(int i=0;i<cnt;i++){
            if(i!=cnt-1){
                printf("%05d %d %05d\n",list[i].add,list[i].data,list[i+1].add);
            }else {
                printf("%05d %d -1\n",list[i].add,list[i].data);
            }
        }
    }
    return 0;
}