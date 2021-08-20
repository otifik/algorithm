/*
1. 因为二叉搜索树的中序满足：是一组序列的从小到大排列，所以只需将所给序列排序即可得到中序数组in
2. 假设把完全二叉树按从左到右、从上到下的顺序依次编号，根节点为0，则从根结点root = 0开始中序遍历，root结点的左孩子下标是root*2+1，右孩子下标是root*2+2
3. 因为是中序遍历，所以遍历结果与中序数组in中的值从0开始依次递增的结果相同，即in[t++]（t从0开始），将in[t++]赋值给level[root]数组
4. 因为树是按从左到右、从上到下的顺序依次编号的，所以level数组从0到n-1的值即所求的层序遍历的值，输出level数组即可～
*/
#include<iostream>
#include<algorithm>
using namespace std;
int in[1010],level[1010],n,t=0;
void inOrder(int root){//对完全二叉树的中序遍历，root表示下标
    if(root>=n) return;
    inOrder(root*2+1);
    level[root]=in[t++];
    cout<<root;
    inOrder(root*2+2);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    sort(in,in+n);
    inOrder(0);
    for(int i=0;i<n;i++){
        if(i){
            cout<<" ";
        }
        cout<<level[i];
    }
    return 0;
}