#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long p;
long long m,M;
long long num[100010];
int main(){
    cin>>n>>p;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num+n);
    int max=-1;
    long long temp=-1;
    int index=0;
    for(int i=0;i<n;i++){
        temp=p*num[i];
        for(int j=index;j<n;j++){
            /*
            优化：不满足条件的时候，break
            满足条件，就进行最大值的判断
            由于temp是当前小的数乘参数p
            所以这时满足条件的num[j]是小于temp的
            当小的数增大，那么num[j]也不用从0开始遍历
            直接从上一个满足的点开始遍历就行
            */
            if(temp<num[j]){
                break;
            }
            if(j-i+1>=max){
                max=j-i+1;
            }
            index=j;
        }
    }
    cout<<max;
    return 0;
}