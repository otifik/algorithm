#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
struct node {
    int productNum;
    vector<int> next;
    int layer;
}manager[100010];
queue<node> que;
int n;
double price,rate;
double sum;
int main(){
    cin>>n>>price>>rate;
    int k,id;
    int num;
    for(int i=0;i<n;i++){
        cin>>k;
        if(k){
            for(int j=0;j<k;j++){
                cin>>id;
                manager[i].next.push_back(id);
            }
        }else {
            cin>>num;
            manager[i].productNum=num;
        }
    }
    manager[0].layer=0;
    que.push(manager[0]);
    while(!que.empty()){
        node front = que.front();
        que.pop();
        if(!front.next.size()){
            sum+=front.productNum*price*pow(1+rate/100,front.layer);
        }else {
            for(int i=0;i<front.next.size();i++){
                node temp = manager[front.next[i]];
                temp.layer = front.layer+1;
                que.push(temp);
            }
        }
    }
    printf("%.1f",sum);
    return 0;
}