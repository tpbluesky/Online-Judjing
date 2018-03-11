#include <stdio.h>
#include <string.h>

int main(){
	char str[100];
	while(scanf("%s",str) == 1){
		if(str[strlen(str)-1] == '.'){
			printf("%d\n",strlen(str)-1);
		}else{
			printf("%d ",strlen(str));
		}
	}
	
} 
