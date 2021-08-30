#include <iostream>
using namespace std;
int main() {
    string s;
    int pos = s.find('E');
    string t = s.substr(1,pos-1);
    int n = stoi(s.substr(pos+1));
    if(s[0]=='-')cout<<"-";
    if(n<0){
        cout<<"0.";
        for(int j=0;j<abs(n)-1;j++) cout<<"0";
        for(int j=0;j<t.length();j++){
            if(t[j]!='.'){
                cout<<t[j];
            }
        }
    }else {
        cout<<t[0];
        int cnt,j;
        for(j=2,cnt=0;j<t.length()&&cnt<n;j++,cnt++) cout<<t[j];
        if(j==t.length()){
            for(int k=0;k<n-cnt;k++) cout<<"0";//指数超过小数位数
        }else {
            cout<<".";
            for(int k=j;k<t.length();k++) cout<<t[k];//指数小于小数位数
        }
    }
    return 0;
}