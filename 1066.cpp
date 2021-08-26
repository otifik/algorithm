/*
LL型
①将A的左孩子B提升为新的根结点；
②将原来的根结点A降为B的右孩子；
③各子树按大小关系连接(BL和AR不变，BR调整为A的左子树)。

RR型
①将A的右孩子B提升为新的根结点；
②将原来的根结点A降为B的左孩子；
③各子树按大小关系连接(AL和BR不变，BL调整为A的右子树)。

LR型
①将B的右孩子C提升为新的根结点；
②将原来的根结点A降为C的右孩子；
③各子树按大小关系连接(BL和AR不变，CL和CR分别调整为B的右子树和A的左子树)。

RL型
①将B的左孩子C提升为新的根结点；
②将原来的根结点A降为C的左孩子；
③各子树按大小关系连接(AL和BR不变，CL和CR分别调整为A的右子树和B的左子树)。
*/
#include<iostream>
using namespace std;
struct node{
    int val;
    struct node *left,*right;
};
node* rotateLeft(node *root){
    node *t=root->right;
    root->right=t->left;
    t->left=root;
    return t;
}
node* rotateRight(node *root){
    node *t=root->left;
    root->left=t->right;
    t->right=root;
    return t;
}
node* rotateLeftRight(node *root){
    root->left=rotateLeft(root->left);
    return rotateRight(root);
}
node* rotateRightLeft(node *root){
    root->right=rotateRight(root->right);
    return rotateLeft(root);
}
int getHeight(node *root){
    if(root==NULL){
        return 0;
    }
    return max(getHeight(root->left),getHeight(root->right))+1;
}
node* insert(node *root,int val){
    if(root==NULL){
        root=new node;
        root->val=val;
        root->left=root->right=NULL;
    }else if(val<root->val){
        root->left=insert(root->left,val);
        if(getHeight(root->left)-getHeight(root->right)==2){
            root= val < root->left->val ? rotateRight(root):rotateLeftRight(root);
        }
    }else {
        root->right=insert(root->right,val);
        if(getHeight(root->left)-getHeight(root->right)==-2){
            root= val > root->right->val ? rotateLeft(root):rotateRightLeft(root);
        }
    }
    return root;
}
int main(){
    int n,val;
    scanf("%d",&n);
    node *root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        root=insert(root,val);
    }
    printf("%d",root->val);
    return 0;
}