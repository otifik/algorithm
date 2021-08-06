#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s,doubleS="";
int digit[10];
int doubleDigit[10];
int remain=0;
int main(){
    cin>>s;
    for(int i=s.length()-1;i>=0;i--){
        int num = s[i]-'0';
        num=num*2+remain;
        remain=num/10;
        doubleS+=(num%10+'0');
    }
    if(remain){
        doubleS+=(remain+'0');
    }
    reverse(doubleS.begin(),doubleS.end());
    for(int i=0;i<s.length();i++){
        digit[s[i]-'0']++;
    }
    for(int i=0;i<doubleS.length();i++){
        doubleDigit[doubleS[i]-'0']++;
    }
    for(int i=0;i<10;i++){
        if(digit[i]!=doubleDigit[i]){
            cout<<"No"<<endl<<doubleS;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    cout<<doubleS;
    return 0;
}