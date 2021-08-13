//LIS：最长上升子序列
//dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度
//最长上升子序列：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-she-ji-fang-fa-zhi-pai-you-xi-jia/
#include<iostream>
#include<vector>
using namespace std;
int book[10005],a[10005],dp[10005];
int main(){
    int n,m,x,l,num=0,maxn=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x;
        book[x]=i;
    }
    cin>>l;
    for(int i=0;i<l;i++){
        cin>>x;
        if(book[x]>=1){
            a[num++]=book[x];
        }
    }
    for(int i=0;i<num;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(a[i]>=a[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        maxn = max(dp[i],maxn);
    }
    cout<<maxn;
}