#include <stdio.h>
#include <string.h>

const int maxn = 1005;

char str1[maxn], str2[maxn];

int a[maxn], b[maxn], ans[maxn];

int len1 , len2 , ans_len;

void change(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
//	for(int i = 0;i < maxn;++i){
//		a[i] = b[i] = 0
//	}
	len1 = strlen(str1);
	len2 = strlen(str2);
	ans_len = len1>len2?len1:len2;
	for(int i = strlen(str1)-1, j = 0;i >= 0;i--){
		a[j++] = str1[i]-'0';
	}
	for(int i = strlen(str2)-1, j = 0;i >= 0;i--){
		b[j++] = str2[i]-'0';
	}
}

void add(){
	int i = 0, r = 0;
	while(i < len1 || i < len2){
		int t = a[i]+b[i]+r;
		r = t/10;
		ans[i++] = t%10;
	} 
	if(r != 0){
		ans[i] = r;
		ans_len++;
	}
}

int main(){
	scanf("%s %s",str1,str2);
	change();
	add();
	for(int i = ans_len-1;i >= 0;--i)
		printf("%d",ans[i]);
	printf("\n"); 
} 

