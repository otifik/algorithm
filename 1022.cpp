//题目大意：给定书的信息，给出查询条件，找出符合条件书籍的id
//暴力出奇迹！！！
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
string id,title,name,keyword,publisher,year;
char ch;
map<string,set<string>> titleMap;
map<string,set<string>> nameMap;
map<string,set<string>> keywordMap;
map<string,set<string>> publisherMap;
map<string,set<string>> yearMap;
int n,m,num;
string s;
int main(){
    cin>>n;
    while(n--){
        cin>>id;
        getchar();
        getline(cin,title);
        titleMap[title].insert(id);
        getline(cin,name);
        nameMap[name].insert(id);
        while(1){
            cin>>keyword;
            keywordMap[keyword].insert(id);
            ch = getchar();
            if(ch=='\n'){
                break;
            }
        }
        getline(cin,publisher);
        publisherMap[publisher].insert(id);
        cin>>year;
        yearMap[year].insert(id);
    }
    cin>>m;
    while(m--){
        scanf("%d: ",&num);
        getline(cin,s);
        cout<<num<<": "<<s<<endl;
        if(num==1){
            if(titleMap[s].size()){
                for(auto it=titleMap[s].begin();it!=titleMap[s].end();it++){
                    cout<<*it<<endl;
                }
            }else {
                cout<<"Not Found"<<endl;
            }
        }else if(num==2){
            if(nameMap[s].size()){
                for(auto it=nameMap[s].begin();it!=nameMap[s].end();it++){
                    cout<<*it<<endl;
                }
            }else {
                cout<<"Not Found"<<endl;
            }
        }else if(num==3){
            if(keywordMap[s].size()){
                for(auto it=keywordMap[s].begin();it!=keywordMap[s].end();it++){
                    cout<<*it<<endl;
                }
            }else {
                cout<<"Not Found"<<endl;
            }
        }else if(num==4){
            if(publisherMap[s].size()){
                for(auto it=publisherMap[s].begin();it!=publisherMap[s].end();it++){
                    cout<<*it<<endl;
                }
            }else {
                cout<<"Not Found"<<endl;
            }
        }else if(num==5){
            if(yearMap[s].size()){
                for(auto it=yearMap[s].begin();it!=yearMap[s].end();it++){
                    cout<<*it<<endl;
                }
            }else {
                cout<<"Not Found"<<endl;
            }
        }
    }
    return 0;
}