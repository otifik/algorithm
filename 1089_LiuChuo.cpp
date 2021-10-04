//切入点：插入排序的顺序性
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[110],b[110],i,j;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(i=0;i<n-1&&b[i]<=b[i+1];i++);
    for(j=i+1;a[j]==b[j]&&j<n;j++);
    if(j==n){
        cout<<"Insertion Sort"<<endl;
        sort(a,a+i+2);
    }else {
        cout<<"Merge Sort"<<endl;
        int k=1,flag=1;
        while(flag){
            flag=0;
            for(int i=0;i<n;i++){
                if(a[i]!=b[i]){
                    flag=1;
                }
            }
            k*=2;
            for(int i=0;i<n/k;i++){
                sort(a+i*k,a+(i+1)*k);
            }
            sort(a+n/k*k,a+n);//处理余下部分数字的归并
            
        }
    }
    for(j=0;j<n;j++){
        if(j) cout<<" ";
        cout<<a[j];
    }
    return 0;
}