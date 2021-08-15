#include<iostream>
using namespace std;
string s1,s2;
int vis[150];
int main(){
    getline(cin,s1);
    getline(cin,s2);
    for(int i=0;i<s2.length();i++){
        vis[s2[i]]=1;
    }
    for(int i=0;i<s1.length();i++){
        if(!vis[s1[i]]){
            cout<<s1[i];
        }
    }
    return 0;
}