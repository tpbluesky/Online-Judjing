#include <stdio.h>

const int maxn = 105;

int n;
int a[maxn][maxn];

int main(){
	scanf("%d",&n);
	for(int i = 0;i < n;++i)
		for(int j = 0;j < n;++j){
			scanf("%d",&a[i][j]);
		}
	for(int i = 0;i < n;++i)
		for(int j= i+1;j < n;++j){
			int t = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = t;
		}
	for(int i = 0;i < n;++i)
		for(int j = 0;j < n;++j)
			printf(j == n-1?"%d\n":"%d ",a[i][j]);
	return 0;
} 
