#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int m,n,k;
vector<int> vec;
int main(){
    cin>>m>>n>>k;
    vec.resize(n+1);
    for(int i=0;i<k;i++){
        bool flag = false;
        stack<int> s;
        for(int j=1;j<=n;j++){
            cin>>vec[j];
        }
        int now = 1;
        for(int j=1;j<=n;j++){
            s.push(j);
            if(s.size()>m) break;
            while(!s.empty()&&s.top()==vec[now]){
                s.pop();
                now++;
            }
        }
        if(now == n+1) flag = true;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}