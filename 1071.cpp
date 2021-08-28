//测试点2：是全部的字符串中的单词出现次数
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<sstream>
using namespace std;
string s;
map<string,int> m;
int main(){
    getline(cin,s);
    transform(s.begin(),s.end(),s.begin(),::tolower);
    for(int i=0;i<s.size();i++){
        if(!(s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9')){
            s.replace(i,1," ");
        }
    }
    stringstream ss;
    ss<<s;
    string temp;
    while(ss>>temp){
        m[temp]++;
    }
    string res;
    int times=-1;
    for(auto i=m.begin();i!=m.end();i++){
        if(i->second>times){
            res = i->first;
            times = i->second;
        }
    }
    cout<<res<<" "<<times;
    return 0;
}