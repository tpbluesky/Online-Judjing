#include <stdio.h>
#include <string.h>

int isok(int a){
	return a >= 0 && a <= 255;
}

int main(){
	int a, b, c, d;
	scanf("%d.%d.%d.%d",&a,&b,&c,&d);
	if(isok(a) && isok(b) && isok(c) && isok(d))
		printf("Yes!\n");
	else 
		printf("No!\n");
	return 0;
} 
