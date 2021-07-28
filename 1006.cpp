#include<iostream>
#include<algorithm>
using namespace std;
int n;
string first;
string last;
int maxn=-1;
int minn=86401;
int main(){
    cin>>n;
    string id;
    for(int i=0;i<n;i++){
        cin>>id;
        int h1,m1,s1,h2,m2,s2;
        scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
        int t1=h1*3600+m1*60+s1;
        int t2=h2*3600+m2*60+s2;
        if(t1<minn){
            minn=t1;
            first = id;
        }
        if(t2>maxn){
            maxn=t2;
            last = id;
        }
    }
    cout<<first<<" "<<last;
    return 0;
}