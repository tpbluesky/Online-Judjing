#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node * next;
}Node,*List;

void insert(List list,int val){
	Node *t = (Node *)malloc(sizeof(Node));
	t->val = val;
	t->next = NULL;
	Node *h = list;
	while(h->next && val > h->next->val){
		h = h->next;
	}
	t->next = h->next;
	h->next = t;
}

void print(List list){
	Node *p = list->next;
	int flag = 1;
	while(p){
		if(flag){
			printf("%d",p->val);
			flag = 0;
		}else	printf(" %d",p->val);
		p = p->next;
	}
	printf("\n");
}

int main(){
	int n, a;
	List list = (Node *)malloc(sizeof(Node));
	list->next = NULL;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		insert(list,a);
	}
	print(list);
	return 0;
}
