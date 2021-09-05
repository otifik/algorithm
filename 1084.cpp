#include<algorithm>
#include<iostream>
using namespace std;
string origin,input,s;
int main(){
    cin>>origin>>input;
    transform(origin.begin(),origin.end(),origin.begin(),::toupper);
    transform(input.begin(),input.end(),input.begin(),::toupper);
    for(int i=0;i<origin.length();i++){
        if(input.find(origin[i])==-1){
            if(s.find(origin[i])==-1){
                s+=origin[i];
            }
        }
    }
    cout<<s;
    return 0;
}