#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

typedef struct node{
	char val;
	int pos;
	struct node *lchild, *rchild;
}Node, *Tree;

char pre[30], mid[30];
int len;

int locate(char c){
	for(int i = 0;i < len;++i){
		if(c == mid[i]) return i;
	}
	return -1;
}

void insert(Tree &t,char val,int pos){
	if(t == NULL){
		t = (Node *)malloc(sizeof(Node));
		t->val = val;
		t->pos = pos; 
		t->lchild = t->rchild = NULL;
		return;
	}
	if(pos < t->pos) insert(t->lchild,val,pos);
	else insert(t->rchild,val,pos);
}

void print(Tree &t){
	if(t == NULL) return;
	if(t->lchild != NULL) print(t->lchild);
	if(t->rchild != NULL) print(t->rchild);
	printf("%c",t->val);
}

int main(){
	scanf("%s%s",pre,mid);
	len = strlen(pre);
	Tree tree = NULL;
	for(int i = 0;i < len;++i){
		insert(tree,pre[i],locate(pre[i]));
	}
	print(tree);
	printf("\n");
	return 0;
}
