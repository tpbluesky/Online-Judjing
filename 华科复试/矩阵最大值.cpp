#include <stdio.h>

int a[105][105];

int main(){
	int n, m;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;++i){
		int mx = -1, sum = 0, pos = -1;
		for(int j = 0;j < m;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j] > mx) {
				mx = a[i][j];
				pos = j;
			}
			sum += a[i][j];
		}
		a[i][pos] = sum;
	}
	for(int i = 0;i < n;++i)
		for(int j = 0;j < m;j++)
			printf(j == m-1?"%d\n":"%d ",a[i][j]);
	
	return 0;
}
