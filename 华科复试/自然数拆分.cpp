#include <stdio.h>

int a[100];

void split(int k,int n){
	for(int i = k==0?1:a[k-1];i <= n/2;++i){
		a[k] = i;
		a[k+1] = n-i; 
		for(int j = 0;j <= k+1;++j)
			printf(j == k+1?"%d\n":"%d+",a[j]);
		split(k+1,n-i);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	split(0,n);
	return 0;
}
