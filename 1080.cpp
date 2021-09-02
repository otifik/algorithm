/*
申请者按最终成绩排名，从排名靠前的开始逐一录取。
如果最终成绩并列，则将根据申请者的国家入学考试成绩G进行排名
如果仍然并列，则他们的排名必须相同。
每个申请者可以有K个选择，根据自己的选择录取：如果按照排名，轮到自己录取；
并且如果一个人最喜欢的shcool的名额没有超过，那么一个人会被这所学校录取，或者一个人的其他选择将被一一考虑。
如果一个人被所有首选学校拒绝，那么这个不幸的申请人将被拒绝。
如果排名相同，并且相应的申请人申请同一所学校，则该学校必须录取所有排名相同的申请人，即使会超过其配额。
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
    int num;
    int GE,GI;
    int choice[5];
    int rank;
    bool isAdmitted;
};
vector<node> stu;
vector<int> school;
vector<int> schoolAdmit[110];
int n,m,k;
bool cmp(node a,node b){
    if(a.GE+a.GI!=b.GE+b.GI){
        return a.GE+a.GI>b.GE+b.GI;
    }else {
        return a.GE>b.GE;
    }
}
int main(){
    cin>>n>>m>>k;
    stu.resize(n);
    school.resize(m);
    for(int i=0;i<m;i++){
        cin>>school[i];
    }
    for(int i=0;i<n;i++){
        stu[i].num=i;
        cin>>stu[i].GE>>stu[i].GI;
        for(int j=0;j<k;j++){
            cin>>stu[i].choice[j];
        }
    }
    sort(stu.begin(),stu.end(),cmp);
    stu[0].rank=1;
    for(int i=1;i<n;i++){
        if(stu[i].GE+stu[i].GI==stu[i-1].GE+stu[i-1].GI&&stu[i].GE==stu[i-1].GE){
            stu[i].rank=stu[i-1].rank;
        }else {
            stu[i].rank=i+1;
        }
    }
    for(int i=0;i<n;i++){
        if(stu[i].isAdmitted){
            continue;
        }
        for(int j=0;j<k;j++){
            if(school[stu[i].choice[j]]>0){
                // school[stu[i].choice[j]]--;
                // schoolAdmit[stu[i].choice[j]].push_back(stu[i].num);
                // stu[i].isAdmitted=true;
                // break;
                vector<int> sameRank;//具有相同排名的人的下标
                vector<int> same;//排名相同并且选择一样的人
                int tempRank = stu[i].rank;
                int cnt=0;
                while(stu[i+cnt].rank==tempRank){
                    sameRank.push_back(i+cnt);
                    cnt++;
                }
                for(int p=0;p<cnt;p++){
                    if(stu[sameRank[p]].isAdmitted){
                        continue;
                    }
                    int flag=0;
                    for(int q=0;q<j;q++){
                        if(stu[sameRank[p]].choice[q]!=stu[i].choice[q]){
                            flag=1;
                        }
                    }
                    if(!flag){
                        same.push_back(sameRank[p]);
                    }
                }
                for(int p=0;p<same.size();p++){
                    schoolAdmit[stu[i].choice[j]].push_back(stu[same[p]].num);
                    stu[same[p]].isAdmitted=true;
                    school[stu[i].choice[j]]--;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        sort(schoolAdmit[i].begin(),schoolAdmit[i].end());
        for(int j=0;j<schoolAdmit[i].size();j++){
            if(j){
                cout<<" ";
            }
            cout<<schoolAdmit[i][j];
        }
        cout<<endl;
    }
}