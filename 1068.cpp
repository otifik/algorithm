#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int w[10010],dp[10010];
int n,m;
bool choice[10010][10010];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    sort(w+1,w+n+1,greater<int>());
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            if(dp[j]<=dp[j-w[i]]+w[i]){
                choice[i][j]=true;
                dp[j]=dp[j-w[i]]+w[i];
            }
        }
    }
    if(dp[m]!=m){
        cout<<"No Solution";
    }else {
        vector<int> arr;
        int v=m,index=n;
        while(v){
            if(choice[index][v]){
                arr.push_back(w[index]);
                v-=w[index];
            }
            index--;
        }
        for(int i=0;i<arr.size();i++){
            if(i) cout<<" ";
            cout<<arr[i];
        }
    }
}