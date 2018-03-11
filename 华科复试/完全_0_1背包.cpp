#include <stdio.h>
#include <string.h>
const int maxn = 105;

int p[maxn], w[maxn], dp[maxn][maxn];
int n, m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;++i)
		scanf("%d%d",&w[i],&p[i]);
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= n;++i){
		for(int j = 0;j <= m;j++){
			if(j >= w[i]){
				int t = dp[i-1][j-w[i]]+p[i];
				dp[i][j] = dp[i-1][j]>t?dp[i-1][j]:t;
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}	
	}
	for(int i = 1;i <= n;++i)
		for(int j = 0;j <= m;j++)
			printf(j == m?"%d\n":"%d ",dp[i][j]);
	printf("%d\n",dp[n][m]);
	return 0;
}
/*
3 6
2 1
3 2
4 5
*/
