//坑点：测试点2、4代表了当b进制下的某一位可能大于10，不能用字符串存
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> vec,temp;
int n,b;
int flag;
int main(){
    cin>>n>>b;
    while(n){
        vec.push_back(n%b);
        n/=b;
    }
    temp = vec;
    reverse(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        if(vec[i]!=temp[i]){
            flag=1;
            break;
        }
    }
    if(!flag){
        cout<<"Yes"<<endl;
    }else {
        cout<<"No"<<endl;
    }
    for(int i=0;i<vec.size();i++){
        if(i!=0){
            cout<<" ";
        }
        cout<<vec[i];
    }
    return 0;
}