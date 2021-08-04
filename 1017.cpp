#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
    int come;
    int time;
}tempCust;
bool cmp(struct node a,struct node b){
    return a.come<b.come;
}
int n,k;
vector<node> cust;
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int h,m,s,t;
        scanf("%d:%d:%d %d",&h,&m,&s,&t);
        int cometime = h*3600+m*60+s;
        if(cometime>61200) continue;
        tempCust = {cometime,t*60};
        cust.push_back(tempCust);
    }
    sort(cust.begin(),cust.end(),cmp);
    vector<int> window(k,28800);
    double res = 0.0;
    for(int i=0;i<cust.size();i++){
        int tempIndex=0,minFinish=window[0];
        for(int j=1;j<k;j++){
            if(minFinish>window[j]){
                minFinish = window[j];
                tempIndex = j;
            }
        }
        if(window[tempIndex]<=cust[i].come){
            window[tempIndex]=cust[i].come + cust[i].time;
        }else {
            res+=(window[tempIndex]-cust[i].come);
            window[tempIndex]+=cust[i].time;
        }
    }
    if(cust.size()==0){
        printf("0.0");
    }else {
        printf("%.1f",res/60/cust.size());
    }
    return 0;
}