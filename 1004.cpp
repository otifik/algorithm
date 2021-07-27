#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m;
const int maxn=105;
struct node{
    int floor;//当前节点所在的层数
    vector<int> child;//当前节点所有的孩子
}Node[maxn];
void bfs(int root){
    queue<int> que;
    que.push(root);
    int floor = Node[root].floor;
    int cnt=0;//表示当前层有多少叶子节点
    while(!que.empty()){
        int front = que.front();
        que.pop();
        if(Node[front].floor!=floor){
            cout<<cnt<<" ";
            floor=Node[front].floor;
            cnt=0;
        }
        if(Node[front].child.size()==0){
            cnt++;
        } else {
            for(int i=0;i<Node[front].child.size();i++){
                que.push(Node[front].child[i]);
            }
        }
    }
    cout<<cnt;
}
int main(){
    int id,k,ch;
    cin>>n>>m;
    Node[1].floor=1;
    for(int i=0;i<m;i++){
        cin>>id>>k;
        for(int j=0;j<k;j++){
            cin>>ch;
            Node[id].child.push_back(ch);//加入当前节点的孩子中
            Node[ch].floor=Node[id].floor+1;//设置孩子节点的层数为父节点+1
        }
    }
    bfs(1);
    return 0;
}