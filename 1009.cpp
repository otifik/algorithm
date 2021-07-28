#include<iostream>
using namespace std;
struct node {
    int exp;
    double coe;
}a[1010],b[1010];
double c[2010];
int cnta;
int cntb;
int exp;
double coe;
int cnt;
int main(){
    cin>>cnta;
    for(int i=0;i<cnta;i++){
        cin>>exp>>coe;
        a[i].exp=exp;
        a[i].coe=coe;
    }
    cin>>cntb;
    for(int i=0;i<cntb;i++){
        cin>>exp>>coe;
        b[i].exp=exp;
        b[i].coe=coe;
    }
    for(int i=0;i<cnta;i++){
        for(int j=0;j<cntb;j++){
            exp = a[i].exp + b[j].exp;
            coe = a[i].coe*b[j].coe;
            c[exp]+=coe;
        }
    }
    for(int i=0;i<2010;i++){
        if(c[i]!=0){
            cnt++;
        }
    }
    cout<<cnt;
    for(int i=2009;i>=0;i--){
        if(c[i]!=0){
            printf(" %d %.1f",i,c[i]);
        }
    }
    return 0;
}