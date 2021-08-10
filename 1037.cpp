#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int nc,np;
vector<int> coupon;
vector<int> product;
int totalValue;
int main(){
    cin>>nc;
    coupon.resize(nc);
    for(int i=0;i<nc;i++){
        cin>>coupon[i];
    }
    cin>>np;
    product.resize(np);
    for(int i=0;i<np;i++){
        cin>>product[i];
    }
    sort(coupon.begin(),coupon.end(),greater<int>());
    sort(product.begin(),product.end(),greater<int>());
    int index=0;
    for(int i=0;i<nc;i++){
        if(coupon[i]>0&&product[index]>0){
            totalValue+=coupon[i]*product[index];
            index++;
        }else {
            break;
        }
    }
    index=np-1;
    for(int i=nc-1;i>=0;i--){
        if(coupon[i]<0&&product[index]<0){
            totalValue+=coupon[i]*product[index];
            index--;
        }else {
            break;
        }
    }
    cout<<totalValue;
    return 0;
}