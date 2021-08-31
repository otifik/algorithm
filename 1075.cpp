/*
坑点：
测试提交实得0分和提交编译不通过为0分需要区分
满分重复通过，计数不累加
*/
//-2表示没交，-1表示编译通过编译不通过
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
struct node {
    int num;
    int score[6]={-2,-2,-2,-2,-2,-2};
    int total;
    int cnt;
}student[10010];
int fullScore[6];
int n,k,m;
vector<node> vec;
bool cmp(node a,node b){
    if(a.total!=b.total){
        return a.total>b.total;
    }else if(a.cnt!=b.cnt){
        return a.cnt>b.cnt;
    }else {
        return a.num<b.num;
    }
}
int main(){
    cin>>n>>k>>m;
    for(int i=1;i<=k;i++){
        cin>>fullScore[i];
    }
    int num,proNum,score;
    for(int i=0;i<m;i++){
        cin>>num>>proNum>>score;
        student[num].num=num;
        if(score==-1&&student[num].score[proNum]==-2){
            student[num].score[proNum]=-1;
        }else if(score>=0&&score>student[num].score[proNum]){
            int origin=student[num].score[proNum];
            if(origin==-1||origin==-2){
                origin=0;
            }
            student[num].total=student[num].total-origin+score;
            if(score==fullScore[proNum]&&student[num].score[proNum]!=fullScore[proNum]){
                student[num].cnt++;
            }
            student[num].score[proNum]=score;
        }
    }
    sort(student+1,student+n+1,cmp);
    for(int i=1;i<=n;i++){
        int flag=0;
        for(int j=1;j<=k;j++){
            if(student[i].score[j]>=0){//编译通过
                flag=1;
                break;
            }
        }
        if(flag){
            vec.push_back(student[i]);
        }
    }
    int temp=1;
    for(int i=0;i<vec.size();i++){
        if(i&&vec[i].total!=vec[i-1].total){
            temp=i+1;
        }
        printf("%d %05d %d",temp,vec[i].num,vec[i].total);
        for(int j=1;j<=k;j++){
            if(vec[i].score[j]==-2){
                cout<<" -";
            }else if(vec[i].score[j]==-1){
                cout<<" 0";
            }else {
                cout<<" "<<vec[i].score[j];
            }
        }
        cout<<endl;
    }
    return 0;
}