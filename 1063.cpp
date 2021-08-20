#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
set<int> s[55];
int n,m,k;
int n1,n2;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        int temp;
        for(int j=0;j<m;j++){
            cin>>temp;
            s[i].insert(temp);
        }
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>n1>>n2;
        int nc=0,nt=s[n2].size();
        for(auto j=s[n1].begin();j!=s[n1].end();j++){
            if(s[n2].find(*j)==s[n2].end()){
                nt++;
            }else {
                nc++;
            }
        }
        printf("%.1f%%\n",100.0*nc/nt);
    }
    return 0;
}