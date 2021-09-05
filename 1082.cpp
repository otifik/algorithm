#include<iostream>
#include<vector>
using namespace std;
string digit[10]={"","yi","er","san","si","wu","liu","qi","ba","jiu"};
string place[4]={"Qian","Bai","Shi",""};
int n;
vector<string> vec;
int num[4];
int main(){
    cin>>n;
    if(n==0){
        cout<<"ling";
        return 0;
    }
    if(n<0){
        cout<<"Fu ";
        n=-n;
    }
    int yi=n/100000000;
    int wan=n%100000000/10000;
    int ge=n%10000;
    if(yi){
        vec.push_back(digit[yi]);
        vec.push_back("Yi");
    }
    //TODO:加零
    int temp=wan;
    if(wan){
        for(int i=3;i>=0;i--){
            num[i]=wan%10;
            wan/=10;
        }
        int cnt=0;
        while(num[cnt]==0){
            cnt++;
        }
        if(cnt!=0&&yi){
            vec.push_back("ling");
        }
        for(int j=cnt;j<4;j++){
            if(j!=3&&j!=cnt&&num[j]==0){
                while(j<4&&num[j]==0){
                    j++;
                }
                j--;
                if(j!=3){
                    vec.push_back("ling");
                }
            }else {
                vec.push_back(digit[num[j]]);
                vec.push_back(place[j]);
            }
        }
        vec.push_back("Wan");
    }
    if(yi&&!temp&&ge){
        vec.push_back("ling");
    }
    if(ge){
        for(int i=3;i>=0;i--){
            num[i]=ge%10;
            ge/=10;
        }
        int cnt=0;
        while(num[cnt]==0){
            cnt++;
        }
        if(cnt!=0&&(temp||yi)){
            vec.push_back("ling");
        }
        for(int j=cnt;j<4;j++){
            if(j!=3&&j!=cnt&&num[j]==0){
                while(j<4&&num[j]==0){
                    j++;
                }
                j--;
                if(j!=3){
                    vec.push_back("ling");
                }
            }else {
                vec.push_back(digit[num[j]]);
                vec.push_back(place[j]);
            }
        }
    }
    for(int i=0;i<vec.size();i++){
        if(vec[i]==""){
            continue;
        }
        if(i){
            cout<<" ";
        }
        cout<<vec[i];
    }
}