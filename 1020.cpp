/*
前序遍历第一位是根节点
中序遍历中，根节点左边的是根节点的左子树，右边是根节点的右子树
后序遍历的最后一个节点即为根节点
*/
#include<iostream>
#include<queue>
using namespace std;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
int pre[30],in[30],post[30];
int n;
int cnt;
node* create(int postL,int postR,int inL,int inR){
    if(postL>postR){
        return NULL;
    }
    node* root = new node;
    root->data=post[postR];
    int k;
    for(k=inL;k<=inR;k++){
        if(in[k]==post[postR]){
            break;
        }
    }
    int numLeft=k-inL; 
    root->lchild=create(postL,postL+numLeft-1,inL,k-1);
    root->rchild=create(postL+numLeft,postR-1,k+1,inR);
    return root;
}
void traversal(node* root){
    queue<node*> que;
    que.push(root);
    while(!que.empty()){
        node* front = que.front();
        que.pop();
        cout<<front->data;
        cnt++;
        if(cnt<n){
            cout<<" ";
        }
        if(front->lchild!=NULL){
            que.push(front->lchild);
        }
        if(front->rchild!=NULL){
            que.push(front->rchild);
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>post[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    node* root=create(0,n-1,0,n-1);
    traversal(root);
    return 0;
}