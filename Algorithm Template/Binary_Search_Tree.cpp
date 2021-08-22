#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

void del(BinTree BST,ElementType X){//可能会有内存溢出
	BinTree node = Find(BST,X);
	if(node->Left&&node->Right){
		BinTree t = node->Right;
		BinTree parent = NULL;
		while(t->Left){
			parent = t;
			t = t->Left;
		}
		node->Data = t->Data;
		parent->Left=NULL;
	}else{
		if(node->Left){
			node = node->Left;
		}else {
			node = node->Right;
		}
	}
}

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        del(BST,X);
    }

    return 0;
}
/* 你的代码将被嵌在这里 */
BinTree Insert(BinTree BST,ElementType X){
	if(!BST){
		BST = (BinTree)malloc(sizeof(BinTree));
		BST->Data = X;
		BST->Left=BST->Right=NULL;
		return BST;
	}else if(X<BST->Data){
		BST->Left=Insert(BST->Left,X);
	}else if(X>BST->Data){
		BST->Right=Insert(BST->Right,X);
	}
	return BST;
}
Position Find(BinTree BST,ElementType X){
	if(!BST){
		return NULL;
	}
	if(BST->Data==X){
		return BST;
	}else if(X<BST->Data){
		return Find(BST->Left,X);
	}else{
		return Find(BST->Right,X);
	}
}
Position FindMax(BinTree BST){
	if(BST){
		while(BST->Right){
			BST=BST->Right;
		}
	}
	return BST;
}
Position FindMin(BinTree BST){
	if(BST){
		while(BST->Left){
			BST=BST->Left;
		}
	}
	return BST;
}
BinTree Delete(BinTree BST,ElementType X){
	if(!BST){
		printf("Not Found\n");
	}else {
		if(X<BST->Data){
			BST->Left=Delete(BST->Left,X);
		}else if(X>BST->Data){
			BST->Right=Delete(BST->Right,X);
		}else {
			if(BST->Left&&BST->Right){
				BinTree t = FindMin(BST->Right);//找右右子树最小来替换被删除节点的数据
				BST->Data = t->Data;
				BST->Right = Delete(BST->Right,t->Data);//删除那个右子树最小的节点
			}else{
				if(BST->Left){
					BST = BST->Left;
				}else {
					BST = BST->Right;
				}
			}
		}
	}
	return BST;
}