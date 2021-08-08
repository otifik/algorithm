#include<iostream>
using namespace std;
int capacity,dis,disPerUnit,n;
struct node {
    double price;
    int dis;
}station[520];
int main(){
    for(int i=0;i<n;i++){
        cin>>station[i].price>>station[i].dis;
    }
    return 0;
}