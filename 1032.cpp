#include<iostream>
#define ll long long
const int maxn = 1e5 + 10;
using namespace std;
struct NODE{
    char data;
    int next;
    bool flag;
}node[maxn];
int main(){
    //std::ios::sync_with_stdio(false);
    for(int i=0;i<maxn;i++){
        node[i].flag=false;
    }
    int s1,s2,n;
    scanf("%d %d %d",&s1,&s2,&n);
    int address,next;
    char data;
    for(int i=0;i<n;i++){
        scanf("%d %c %d",&address,&data,&next);
        node[address].data=data;
        node[address].next=next;
    }
    int p;
    for(p=s1;p!=-1;p=node[p].next){
        node[p].flag=true;
    }
    for(p=s2;p!=-1;p=node[p].next){
        if(node[p].flag==true){
            break;
        }
    }
    if(p!=-1){
        printf("%05d",p);
    }else {
        cout<<-1;
    }
    return 0;
}

//后面dogshit
/*
#include<iostream>
using namespace std;
const int maxn=100010;
struct node {
    char data;
    int next;
    int cnt;
}letter[maxn];
int startA,startB;
int n,s;
int address,nextAdd;
char ch;
int main(){
    cin>>startA>>startB>>n;
    if(startA==-1||startB==-1){
        cout<<"-1";
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>address>>ch>>nextAdd;
        letter[address].data=ch;
        letter[address].next=nextAdd;
        letter[address].cnt=0;
    }
    s=startA;
    do{
        letter[s].cnt++;
        s=letter[s].next;
    }while(letter[s].next!=-1);
    s=startB;
    do{
        letter[s].cnt++;
        s=letter[s].next;
    }while(letter[s].next!=-1);
    int res=-1;
    s=startA;
    do{
        if(letter[s].cnt==2){
            res=s;
            break;
        }
        s=letter[s].next;
    }while(letter[s].next!=-1);
    if(res!=-1){
        printf("%05d",res);
    }else {
        printf("-1");
    }
    return 0;
}
*/