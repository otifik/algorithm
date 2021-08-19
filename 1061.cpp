//坑点：一周只有七天，A到G
#include<string>
#include<iostream>
using namespace std;
string day[8]={"","MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int cnt=0;
    for(int i=0;i<min(s1.length(),s2.length());i++){
        if(s1[i]==s2[i]&&(s1[i]>='A'&&s1[i]<='N'||s1[i]>=0&&s1[i]<='9')&&cnt==1){
            if(s1[i]>='A'&&s1[i]<='N'){
                int temp=10+(s1[i]-'A');
                printf("%02d",temp);
            }else {
                int temp=s1[i]-'0';
                printf("%02d",temp);
            }
            cout<<":";
            break;
        }
        if(s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G'&&cnt==0){
            cout<<day[s1[i]-'A'+1]<<" ";
            cnt++;
        }
    }
    for(int i=0;i<min(s3.length(),s4.length());i++){
        if(s3[i]==s4[i]&&(s3[i]>='a'&&s3[i]<='z'||s3[i]>='A'&&s3[i]<='Z')){
            printf("%02d",i);
            break;
        }
    }
    return 0;
}