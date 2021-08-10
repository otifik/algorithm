#include<iostream>
#include<vector>
using namespace std;
struct node {
    string account;
    string password;
}temp;
vector<node> modified;
vector<node> unmodified;
int n;
int check(node &a){
    int flag=0;
    for(int i=0;i<a.password.size();i++){
        if(a.password[i]=='1'){
            a.password[i]='@';
            flag=1;
        }else if(a.password[i]=='0'){
            a.password[i]='%';
            flag=1;
        }else if(a.password[i]=='l'){
            a.password[i]='L';
            flag=1;
        }else if(a.password[i]=='O'){
            a.password[i]='o';
            flag=1;
        }
    }
    return flag;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp.account;
        cin>>temp.password;
        int res = check(temp);
        if(res){
            modified.push_back(temp);
        }else {
            unmodified.push_back(temp);
        }
    }
    if(modified.size()){
        cout<<modified.size()<<endl;
        for(int i=0;i<modified.size();i++){
            cout<<modified[i].account<<" "<<modified[i].password<<endl;
        }
    }else {
        if(unmodified.size()==1&&n==1){
            cout<<"There is 1 account and no account is modified";
        }else {
            cout<<"There are "<<n<<" accounts and no account is modified";
        }
    }
}