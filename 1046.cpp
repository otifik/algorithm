#include<iostream>
#include<vector>
using namespace std;
int n,m;
vector<int> dis;
int sum;
int main(){
    cin>>n;
    dis.resize(n+1);
    int temp;
    for(int i=1;i<=n;i++){
        cin>>temp;
        sum+=temp;
        dis[i]=sum;
    }
    cin>>m;
    int left,right;
    for(int i=0;i<m;i++){
        cin>>left>>right;
        if(left>right){
            swap(left,right);
        }
        temp = dis[right-1] - dis[left - 1];
        cout<<min(temp,sum-temp)<<endl;
    }

    return 0;
}