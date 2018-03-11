#include <stdio.h>

int main(){
	char s[100];
	gets(s);
	int cnt = 0;
	for(int i = 0;s[i] != '\0';++i){
		if(s[i] != ',') s[cnt++] = s[i];
	}
	s[cnt] = '\0';
	int a, b;
	sscanf(s,"%d%d",&a,&b);
	printf("%d\n",a+b);
	
	return 0;
}
