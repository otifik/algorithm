#include<iostream>
#include<math.h>
using namespace std;
long long num1,den1,num2,den2;
long long gcd(long long m, long long n) {
    return n ? gcd(n, m % n) : m;
}
string print(long long num,long long den){
    bool flag = false;
    if(num<0&&den>0||num>0&&den<0){
        flag=true;
    }
    num=fabs(num);
    den=fabs(den);
    string s="";
    long long temp = gcd(num,den);
    if(temp==0){
        return "0";
    }
    num/=temp;
    den/=temp;
    long long shang = num/den;
    long long remain = num%den;
    if(flag){
        s+="(-";
    }
    if(shang!=0){
        s+=to_string(shang);
    }
    if(shang!=0&&remain!=0){
        s+=" ";
    }
    if(remain!=0){
        s+=to_string(remain)+"/"+to_string(den);
    }
    if(remain==0&&shang==0){
        s+="0";
    }
    if(flag){
        s+=")";
    }
    return s;
}
int main(){
    scanf("%lld/%lld %lld/%lld",&num1,&den1,&num2,&den2);
    string s1 = print(num1,den1);
    string s2 = print(num2,den2);
    cout<<s1<<" + "<<s2<<" = "<<print(num1*den2+num2*den1,den1*den2)<<endl;
    cout<<s1<<" - "<<s2<<" = "<<print(num1*den2-num2*den1,den1*den2)<<endl;
    cout<<s1<<" * "<<s2<<" = "<<print(num1*num2,den1*den2)<<endl;
    cout<<s1<<" / "<<s2<<" = ";
    if(s2=="0"){
        cout<<"Inf";
    }else {
        cout<<print(num1*den2,num2*den1);
    }
    return 0;
}