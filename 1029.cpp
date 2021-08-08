/*
开一个数组，在线处理理第二个数组。 第⼀⼆个数组（下标从1开始）分别有n，m个元素，中间
数在(n + m + 1) / 2的位置。所以只要从⼩到大数到(n + m + 1) / 2的位置就行了~ count计总个数 ，给第
一个数组设置指针i，每次从第⼆个数组中读入temp，检查第一个数组中前几个数是不是比temp小，
小就count+1并判断是否到数了了中间数，到了就输出。 如果数完⽐比temp小的数还没到中间数，
count+1，检查temp是不是中间数，是就输出。循环上述过程。如果第二个数组读取完了了，还没数到
中间数，说明中间数在剩下的第一个数组中，就在剩下的数组中数到中间数位置即可
*/

#include<iostream>
using namespace std;
int n,m,temp,cnt;
int k[200005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    k[n+1]=0x7fffffff;
    cin>>m;
    int midPos=(n+m+1)/2;
    int i=1;
    for(int j=1;j<=m;j++){
        cin>>temp;
        while(k[i]<temp){
            cnt++;
            if(cnt==midPos) cout<<k[i];
            i++;
        }
        cnt++;
        if(cnt==midPos) cout<<temp;
    }
    while(i<=n){
        cnt++;
        if(cnt==midPos) cout<<k[i];
        i++;
    }
    return 0;
}