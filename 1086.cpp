#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
vector<int> pre,in,post,value;
void postOrder(int root,int start,int end){
    if(start>end) return;
    int i=start;
    while(i<end&&in[i]!=pre[root]) i++;
    postOrder(root+1,start,i-1);
    postOrder(root+1+i-start,i+1,end);
    post.push_back(pre[root]);
}
int n,num,key;
string str;
stack<int> s;
int main(){
    cin>>n;
    for(int i=0;i<2*n;i++){
        cin>>str;
        if(str=="Push"){
            cin>>num;
            value.push_back(num);
            pre.push_back(key);
            s.push(key++);
        }else {
            in.push_back(s.top());
            s.pop();
        }
    }
    postOrder(0,0,n-1);
    for(int i=0;i<n;i++){
        if(i){
            cout<<" ";
        }
        cout<<value[post[i]];
    }
    return 0;
}