#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int m,n;
int num;
int hashTable[10010];
bool isPrime(int number){
    if(number==1){
        return false;
    }
    for(int i=2;i<=sqrt(number);i++){
        if(number%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    memset(hashTable,-1,sizeof(hashTable));
    cin>>m>>n;
    while(!isPrime(m)){
        m++;
    }
    for(int i=0;i<n;i++){
        if(i){
            cout<<" ";
        }
        cin>>num;
        int flag=0;
        int pos;
        for(int j=0;j<m;j++){
            pos = (num+j*j)%m;
            if(hashTable[pos]==-1){
                hashTable[pos]=num;
                flag=1;
                break;
            }
        }
        if(!flag){
            cout<<"-";
        }else {
            cout<<pos;
        }
    }
    return 0;
}