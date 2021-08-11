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

/*柳神代码，只需要根据二叉树性质左子树小于root，右子树大于root，和前序遍历，即可推导出后序遍历
如果后序遍历出来的节点个数不等于总节点个数，说明这不是二叉搜索树
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> pre,post;
bool isMirror=false;
int n;
void getPost(int root,int tail){
    if(root>tail) return;
    int i=root+1,j=tail;
    if(isMirror){
        while(i<=tail&&pre[root]<=pre[i]) i++;
        while(j>=root+1&&pre[root]>pre[j]) j--;
    }else {
        while(i<=tail&&pre[root]>pre[i]) i++;
        while(j>=root+1&&pre[root]<=pre[j]) j--;
    }
    if(i-j!=1){
        return;
    }
    getPost(root+1,j);
    getPost(i,tail);
    post.push_back(pre[root]);
}
int main(){
    cin>>n;
    pre.resize(n);
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    getPost(0,n-1);
    if(post.size()!=n){
        post.clear();
        isMirror=true;
        getPost(0,n-1);
    }
    if(post.size()==n){
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            if(i){
                cout<<" ";
            }
            cout<<post[i];
        }
    }else cout<<"NO";
    return 0;
}