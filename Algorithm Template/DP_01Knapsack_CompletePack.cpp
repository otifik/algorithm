//滚动数组优化，01背包
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,dp[10010],w[10010],v[10010];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    //完全背包
    // for(int i=1;i<=n;i++){
    //     for(int j=w[i];j<=m;j++){
    //         dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    //     }
    // }
    cout<<dp[m];
    return 0;
}

// //二维数组，01背包
// #include<iostream>
// #include<algorithm>
// using namespace std;
// int n,m,dp[10010][10010],w[10010],v[10010];
// int main(){
//     cin>>n>>m;
//     for(int i=1;i<=n;i++){
//         cin>>w[i]>>v[i];
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             dp[i][j]=dp[i-1][j];
//             if(j>=w[i]){
//                 dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
//             }
//         }
//     }
//     cout<<dp[n][m];
//     return 0;
// }