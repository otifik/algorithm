//对一棵二叉搜索树进行中序遍历，得到就是一个非降序有序序列

#include<iostream>
#include<vector>
using namespace std;
struct node {
    int value;
    node *left,*right;
};
void insert(node* &root,int data){
    if(root == NULL){
        root = new node;
        root->value=data;
        root->left=NULL;
        root->right=NULL;
        return ;
    }
    if(data<root->value) insert(root->left,data);
    else insert(root->right,data);
}
void preOrder(node* root,vector<int>& v){
    if(root == NULL) return;
    v.push_back(root->value);
    preOrder(root->left,v);
    preOrder(root->right,v);
}
void preMirrorOrder(node* root,vector<int>& v){
    if(root==NULL) return;
    v.push_back(root->value);
    preMirrorOrder(root->right,v);
    preMirrorOrder(root->left,v);
}
void postOrder(node* root,vector<int>& v){
    if(root == NULL) return;
    postOrder(root->left,v);
    postOrder(root->right,v);
    v.push_back(root->value);
}
void postMirrorOrder(node* root,vector<int>& v){
    if(root == NULL) return;
    postMirrorOrder(root->right,v);
    postMirrorOrder(root->left,v);
    v.push_back(root->value);
}
int main(){
    int n;
    node* s=NULL;
    cin>>n;
    vector<int> num,pre,preM,post,postM;
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        num.push_back(data);
        insert(s,data);
    }
    preOrder(s,pre);
    preMirrorOrder(s,preM);
    if(num == pre){
        postOrder(s,post);
        cout<<"YES"<<endl;
        for(int i=0;i<post.size();i++){
            if(i!=0){
                cout<<" ";
            }
            cout<<post[i];
        }
    }else if(num == preM){
        postMirrorOrder(s,postM);
        cout<<"YES"<<endl;
        for(int i=0;i<postM.size();i++){
            if(i!=0){
                cout<<" ";
            }
            cout<<postM[i];
        }
    }else {
        cout<<"NO";
    }
    return 0;
}
