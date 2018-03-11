#include <stdio.h>

void hanoi(int n,char s,char t,char f){
	if(n == 1){
		printf("%d:%c->%c\n",n,s,t);	
		return;
	}
	if(n == 2){
		printf("%d:%c->%c\n",1,s,f);
		printf("%d:%c->%c\n",2,s,t);
		printf("%d:%c->%c\n",1,f,t);
		return;
	}
	hanoi(n-1,s,f,t);
	printf("%d:%c->%c\n",n,s,t);
	hanoi(n-1,f,t,s);
}

int main(){
	hanoi(3,'A','C','B');
	return 0;
} 
