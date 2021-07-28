#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string num;
string digit[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
    cin>>num;
    int sum=0;
    for(int i=0;i<num.length();i++){
        sum+=num[i]-'0';
    }
    string s=to_string(sum);
    int flag=0;
    for(int i=0;i<s.length();i++){
        if(flag++){
            cout<<" ";
        }
        cout<<digit[s[i]-'0'];
    }
    return 0;
}