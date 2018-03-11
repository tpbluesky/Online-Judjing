#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *lchild, *rchild;
}Node, *Tree;

void insert(Tree &t,int val){
	if(t == NULL){
		t = (Node *)malloc(sizeof(Node)); 
		t->val = val;
		t->lchild = t->rchild = NULL;
		return;
	}
	if(val < t->val) {
		insert(t->lchild,val);
	}
	else if(val > t->val) {
		insert(t->rchild,val);
	}
}

void pre(Tree &t){
	if(t == NULL) return;
	printf("%d ",t->val);
	pre(t->lchild);
	pre(t->rchild);
}

void mid(Tree &t){
	if(t == NULL) return;
	mid(t->lchild);
	printf("%d ",t->val);
	mid(t->rchild);
}

void last(Tree &t){
	if(t == NULL) return;
	last(t->lchild);
	last(t->rchild);
	printf("%d ",t->val);
}


int main(){
	int n, a;
	while(scanf("%d",&n) == 1){
		Tree tree = NULL;
		for(int i = 0;i < n;++i){
			scanf("%d",&a);
			insert(tree,a);
		}
		pre(tree);
		printf("\n");
		mid(tree);
		printf("\n");
		last(tree);
		printf("\n");
	}
}
