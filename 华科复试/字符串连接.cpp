#include <stdio.h>

char a[205], b[105]; 

int main(){
	scanf("%s%s",a,b);
	int cnt = 0;
	while(a[cnt] != '\0') cnt++;
	int t = 0;
	while(b[t] != '\0') a[cnt++] = b[t++];
	a[cnt] = '\0';
	printf("%s",a);
} 
