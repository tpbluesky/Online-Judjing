#include <stdio.h>


int main(){
	int n;
	scanf("%d",&n);
	int t = n*n;
	int res = 1;
	while(n){
		if(n%10 != t%10) res = 0;
		n /= 10; t /= 10;
	}	
	printf(res?"Yes!\n":"No!\n");
	return 0;
}
