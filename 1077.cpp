#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s[110];
string temp;
int n;
int minLen=1010;
int main(){
    cin>>n;
    getchar();
    for(int i=0;i<n;i++){
        getline(cin,temp);
        reverse(temp.begin(),temp.end());
        s[i]=temp;
        if(temp.length()<minLen){
            minLen=temp.length();
        }
    }
    string suffix="";
    int flag=0;
    for(int i=1;i<=minLen;i++){
        string t = s[0].substr(0,i);
        for(int j=0;j<n;j++){
            if(s[j].substr(0,i)!=t){
                flag=1;
                break;
            }
        }
        if(flag){
            break;
        }
        suffix = t;
    }
    if(suffix==""){
        cout<<"nai";
    }else {
        reverse(suffix.begin(),suffix.end());
        cout<<suffix;
    }
    return 0;
}