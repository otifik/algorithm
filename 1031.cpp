#include<iostream>
#include<string.h>
using namespace std;
string s;
int n,n1,n2,n3;
char ch[100][100];
int main(){
    memset(ch,' ',sizeof(ch));
    cin>>s;
    n=s.length()+2;
    n1=n3=n/3;
    n2=n-2*n1;
    int index=0;
    for(int i=0;i<n1;i++){
        ch[i][0]=s[index++];
    }
    for(int i=1;i<n2-1;i++){
        ch[n1-1][i]=s[index++];
    }
    for(int i=n1-1;i>=0;i--){
        ch[i][n2-1]=s[index++];
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            cout<<ch[i][j];
        }
        cout<<endl;
    }
    return 0;
}