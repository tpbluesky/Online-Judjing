#include <stdio.h>

int a[105][105];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;++i)
		for(int j = 0;j < n;++j)
			scanf("%d",&a[i][j]);
	int res = 1;
	for(int i = 0;i < n;++i)
		for(int j = i+1;j < n;j++)
			if(a[i][j] != a[j][i]){
				res = 0;
				i = n;
				break;
			}
	printf(res==1?"Yes!\n":"No!\n");
}
