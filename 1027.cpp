#include<iostream>
#include<algorithm>
using namespace std;
int red,green,blue;
char mars[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
string marsRed="",marsGreen="",marsBlue="";
int main(){
    cin>>red>>green>>blue;
    if(red==0) marsRed="0";
    if(green==0) marsGreen="0";
    if(blue==0) marsBlue="0";
    while(red){
        marsRed+=mars[red%13];
        red/=13;
    }
    while(green){
        marsGreen+=mars[green%13];
        green/=13;
    }
    while(blue){
        marsBlue+=mars[blue%13];
        blue/=13;
    }
    if(marsRed.length()==1){
        marsRed+="0";
    }
    if(marsGreen.length()==1){
        marsGreen+="0";
    }
    if(marsBlue.length()==1){
        marsBlue+="0";
    }
    reverse(marsRed.begin(),marsRed.end());
    reverse(marsGreen.begin(),marsGreen.end());
    reverse(marsBlue.begin(),marsBlue.end());
    cout<<"#"<<marsRed<<marsGreen<<marsBlue;
    return 0;
}