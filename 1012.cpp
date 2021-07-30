#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
char grade[4]={'A','C','M','E'};
struct node {
    int id,best;
    int score[4],rank[4];
    //ACME
}stu[2100];
int map[1000000];
int n,m;
int id,C,M,E,A;
int flag;
bool cmp(struct node a,struct node b){
    if(flag==0){
        return a.score[0]>b.score[0];
    }else if(flag==1){
        return a.score[1]>b.score[1];
    }else if(flag==2){
        return a.score[2]>b.score[2];
    }else if(flag==3){
        return a.score[3]>b.score[3];
    }
}
int main(){
    memset(map,-1,sizeof(map));
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>id>>C>>M>>E;
        A=(C+M+E)/3;
        stu[i].id=id;
        stu[i].score[0]=A;
        stu[i].score[1]=C;
        stu[i].score[2]=M;
        stu[i].score[3]=E;
    }
    for(int i=0;i<4;i++){
        flag=i;
        sort(stu,stu+n,cmp);
        for(int j=0;j<n;j++){
            stu[j].rank[i]=j+1;
            if(j!=0&&stu[j].score[i]==stu[j-1].score[i]){
                stu[j].rank[i]=stu[j-1].rank[i];
            }
        }
    }
    for(int i=0;i<n;i++){
        map[stu[i].id]=i;
        int temp=10000;
        for(int j=0;j<4;j++){
            if(stu[i].rank[j]<temp){
                temp=stu[i].rank[j];
                stu[i].best=j;
            }
        }
    }
    for(int i=0;i<m;i++){
        cin>>id;
        if(map[id]==-1){
            cout<<"N/A"<<endl;
            continue;
        }
        cout<<stu[map[id]].rank[stu[map[id]].best]<<" "<<grade[stu[map[id]].best]<<endl;
    }
    return 0;
}

