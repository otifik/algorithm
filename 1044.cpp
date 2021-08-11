#include<iostream>
#include<utility>
#include<vector>
using namespace std;
int n,payment;
int value[100005];
struct node {
    int front,tail;
    int sum;
}tempNode;
vector<node> vec;
vector<node> minVec;
int main(){
    cin>>n>>payment;
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    for(int i=0;i<n;i++){
        int start=i;
        int sum=0;
        for(int j=start;j<n;j++){
            sum+=value[j];
            if(sum==payment){
                tempNode.front=i+1;
                tempNode.tail=j+1;
                vec.push_back(tempNode);
                break;
            }
            if(sum>payment){
                tempNode.front=i+1;
                tempNode.tail=j+1;
                tempNode.sum=sum;
                if(minVec.empty()){
                    minVec.push_back(tempNode);
                }else if(!minVec.empty()&&sum<minVec[0].sum){
                    minVec.clear();
                    minVec.push_back(tempNode);
                }else if(!minVec.empty()&&sum==minVec[0].sum){
                    minVec.push_back(tempNode);
                }
                break;
            }
        }
    }
    if(!vec.empty()){
        for(int i=0;i<vec.size();i++){
            cout<<vec[i].front<<"-"<<vec[i].tail<<endl;
        }
    }else {
        for(int i=0;i<minVec.size();i++){
            cout<<minVec[i].front<<"-"<<minVec[i].tail<<endl;
        }
    }
    return 0;
}