/*
    大致思路：把给出基数的数字转化为十进制，再处理另一个数字，多少进制转化为十进制数等于之前被转化的那个数字,使用二分法，如果暴力遍历会出现超时
*/
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
string n1,n2;
long long tag,radix;
//此函数作用在于将给定的一个数值和一个n进制，转化为10进制的数字
long long convert(string s,long long radix){
    long long sum = 0;
    int index = 0,temp = 0;
    for(auto it = s.rbegin();it!=s.rend();it++){
        temp = isdigit(*it)?*it-'0':*it-'a'+10;
        sum+=temp*pow(radix,index++);
    }
    return sum;
}
long long find_radix(string s,long long num){
    /*找出需要算radix的那个数中最大的一个数字或者字母，其+1即可作为二分法的下限值，
    如0x3f3f3f3f，其中最大的数字（字母）就是f，f代表15，+1就是16，就是二分法的下限*/
    char it = *max_element(s.begin(),s.end());
    long long low = (isdigit(it)?it-'0':it-'a'+10)+1;
    /*1 1 1 10，对于这个样例，如果上限取num，则low=2，high=1，这时二分法就不会进行，直接返回-1，输出impossible
    所以一开始num有小于low的可能性，至少保证算法执行一次，就从low和num中取最大值
    对测试点1的解析：https://blog.csdn.net/ZiYuTongXue/article/details/106494434?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162752375416780366567843%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=162752375416780366567843&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~rank_v29-1-106494434.first_rank_v2_pc_rank_v29&utm_term=1010Radix+%2825%29%E7%AC%AC%E4%B8%80%E4%B8%AA%E6%B5%8B%E8%AF%95%E7%82%B9&spm=1018.2226.3001.4187*/
    long long high = max(low,num);
    while(low<=high){
        long long mid =(low+high)/2;
        long long t = convert(s,mid);
        if(t<0||t>num){
            high = mid -1;
        }else if(t==num){
            return mid;
        }else {
            low = mid + 1;
        }
    }
    return -1;
}
int main(){
    cin>>n1>>n2>>tag>>radix;
    long long result = tag==1?find_radix(n2,convert(n1,radix)):find_radix(n1,convert(n2,radix));
    if(result!=-1){
        printf("%lld",result);
    }else {
        printf("Impossible");
    }
    return 0;
}