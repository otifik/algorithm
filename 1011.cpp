#include<iostream>
using namespace std;
char state[3]={'W','T','L'};
double maxn;
double arr[3];
int main(){
    double t;
    int index;
    for(int i=0;i<3;i++){
        maxn = -1;
        for(int j=0;j<3;j++){
            cin>>t;
            if(t>maxn){
                maxn=t;
                index=j;
            }
        }
        arr[i]=maxn;
        cout<<state[index]<<" ";
    }
    double res = (arr[0]*arr[1]*arr[2]*0.65-1)*2;
    printf("%.2f",res);
    return 0;
}