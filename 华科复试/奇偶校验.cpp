#include <stdio.h>

int a[8];

void change(int c){
	for(int i = 0;i < 8;++i) a[i] = 0;
	int t = 7;
	int cnt = 0;
	while(c > 0){
		a[t--] = c%2;
		c /= 2;
		cnt += a[t+1];
	}
	a[0] = (cnt+1)%2;
}

void print(){
	for(int i = 0;i < 8;++i)
		printf("%d",a[i]);
	printf("\n");
}

char str[105];

int main(){
	scanf("%s",str);
	for(int i = 0;str[i] != '\0';++i){
		change(str[i]);
		print();
	}
	return 0;
}
