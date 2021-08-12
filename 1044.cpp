#include<iostream>
using namespace std;
int n,m,sum[100005];
int first=0,minDif = 0x3f3f3f3f;
bool isFind = false;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>sum[i];
        sum[i]+=sum[i-1];
        while(sum[i]-sum[first]>m){
            minDif = min(minDif,sum[i]-sum[first]);
            first++;
        }
        if(sum[i]-sum[first]==m){
            cout<<first+1<<"-"<<i<<endl;
            isFind=true;
        }
    }
    if(!isFind){
        int j=0;
        for(int i=1;i<=n;i++){
            while(sum[i]-sum[j]>minDif){
                j++;
            }
            if(sum[i]-sum[j]==minDif){
                cout<<j+1<<"-"<<i<<endl;
            }
        }
    }
    return 0;
}


/*柳神代码，二分查找*/
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> sum,resultArr;
// int n,m;
// void fun(int i,int &j,int &tempsum){
//     int left = i,right = n;
//     while(left<right){
//         int mid = (left+right)/2;
//         if(sum[mid]-sum[i-1]>=m){
//             right = mid;
//         }else {
//             left = mid + 1;
//         }
//     }
//     j=right;
//     tempsum=sum[j]-sum[i-1];
// }
// int main(){
//     cin>>n>>m;
//     sum.resize(n+1);
//     for(int i=1;i<=n;i++){
//         cin>>sum[i];
//         sum[i]+=sum[i-1];
//     }
//     int minans=sum[n];//表示的是我最少一共拿出多少钱
//     for(int i=1;i<=n;i++){
//         int j,tempsum;
//         fun(i,j,tempsum);
//         if(tempsum>minans) continue;
//         if(tempsum>=m){
//             if(tempsum<minans){
//                 resultArr.clear();
//                 minans=tempsum;
//             }
//             resultArr.push_back(i);
//             resultArr.push_back(j);
//         }
//     }
//     for(int i = 0; i < resultArr.size(); i += 2){
//         printf("%d-%d\n", resultArr[i], resultArr[i+1]);
//     }
//     return 0;
// }