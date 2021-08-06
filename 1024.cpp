#include<iostream>
#include<algorithm>
using namespace std;
int k,num,remain;
string s,temp,res="";
int main(){
    cin>>s>>k;
    for(int i=0;i<k;i++){
        remain = 0;
        temp = s;
        reverse(s.begin(),s.end());
        if(temp == s){
            cout<<s<<endl<<i;
            return 0;
        }
        for(int i=s.length()-1;i>=0;i--){
            num = (s[i]-'0')+(temp[i]-'0')+remain;
            remain = num/10;
            res+=(num%10+'0');
        }
        if(remain){
            res+=(remain+'0');
        }
        reverse(res.begin(),res.end());
        s = res;
        res="";
    }
    cout<<s<<endl<<k;
    return 0;
}