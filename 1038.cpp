#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(string a,string b){
    return a<b;
}
int n;
string s[10010];
string res;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n-1;i++){
        string bpa=s[i]+s[i+1];
        string apb=s[i+1]+s[i];
        if(apb<bpa){
            swap(s[i],s[i+1]);
        }
    }
    for(int i=0;i<n;i++){
        res+=s[i];
    }
    int pos=-1;
    for(int i=0;i<res.size();i++){
        if(res[i]!='0'){
            pos=i;
            break;
        }
    }
    if(pos==-1){
        cout<<0;
        return 0;
    }
    res = res.substr(pos);
    cout<<res;
    return 0;
}

//柳神版
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp0(string a, string b) {
    return a + b < b + a;
}
string str[10010];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        cin >> str[i];
    sort(str, str + n, cmp0);
    string s;
    for(int i = 0; i < n; i++)
        s += str[i];
    while(s.length() != 0 && s[0] == '0')
        s.erase(s.begin());
    if(s.length() == 0) cout << 0;
    cout << s;
    return 0;
}