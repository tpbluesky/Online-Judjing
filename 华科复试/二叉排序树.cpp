#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *lchild, *rchild;
}Node , * Tree;

int insert(Tree &t,int val,int parent){
	if(t == NULL){
		t = (Node *)malloc(sizeof(Node));
		t->lchild = t->rchild = NULL;
		t->val = val;
		return parent;
	}
	if(val < t->val){
		return insert(t->lchild,val,t->val);
	}else{
		return insert(t->rchild,val,t->val);
	}
}

int main(){
	Tree tree = NULL;
	int n, a;
	scanf("%d",&n);
	for(int i = 0;i < n;++i){
		scanf("%d",&a);
		printf("%d\n",insert(tree,a,-1));
	}
	return 0;
}
