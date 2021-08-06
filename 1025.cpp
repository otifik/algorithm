#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
    string id;
    int score;
    int locationNum;
    int localRank;
    int finalRank;
};
vector<node> vec;
int n,k;
bool cmp(struct node a,struct node b){
    if(a.score!=b.score){
        return a.score>b.score;
    }else if(a.id!=b.id){
        return a.id<b.id;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k;
        vector<node> temp(k);
        for(int j=0;j<k;j++){
            cin>>temp[j].id>>temp[j].score;
            temp[j].locationNum=i;
        }
        sort(temp.begin(),temp.end(),cmp);
        temp[0].localRank=1;
        vec.push_back(temp[0]);
        for(int j=1;j<k;j++){
            temp[j].localRank = (temp[j].score==temp[j-1].score)?(temp[j-1].localRank):(j+1);
            vec.push_back(temp[j]);
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    vec[0].finalRank = 1;
    for(int i=1;i<vec.size();i++){
        vec[i].finalRank = (vec[i].score==vec[i-1].score)?vec[i-1].finalRank:(i+1);
    }
    cout<<vec.size();
    for(int i=0;i<vec.size();i++){
        cout<<vec[i].id<<" "<<vec[i].finalRank<<" "<<vec[i].locationNum<<" "<<vec[i].localRank<<endl;
    }
    return 0;
}