#include<iostream>
using namespace std;
int main(){
    int g1,s1,k1,g2,s2,k2;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    int g,s,k;
    int remain;
    k = (k1+k2)%29;
    remain = (k1+k2)/29;
    s = (s1+s2+remain)%17;
    remain = (s1+s2+remain)/17;
    g = g1+g2+remain;
    printf("%d.%d.%d",g,s,k);
    return 0;
}