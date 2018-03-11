#include <stdio.h>
#include <string.h>
#define inf 0x3f3f3f3f
const int maxn = 105;

//int mp[maxn][maxn], dp[maxn];
//
//int main(){
//	int n, m;
//	memset(mp,0x3f,sizeof(mp));
//	scanf("%d%d",&n,&m);
//	for(int i = 0, a, b, c;i < m;++i){
//		scanf("%d%d%d",&a,&b,&c);
//		mp[a][b] = c;
//	}
//	memset(dp,0x3f,sizeof(dp));
//	dp[n] = 0;
//	for(int i = n-1;i > 0;i--){
//		for(int j = i;j <= n;j++){
//			if(mp[i][j] < inf){
////				printf("%d %d\n",i,j);
//				int t = dp[j]+mp[i][j];
//				dp[i] = dp[i]>t?t:dp[i];
//			}
//		}
//	}
//	printf("%d\n",dp[1]);
//} 

int u[maxn], v[maxn], w[maxn], fir[maxn], nex[maxn];
int e_max, dp[maxn];

void init()
{
    memset(fir,-1,sizeof(fir));
    e_max = 0;
}

void add_edge(int a,int b,int c){
	int e = e_max++;
	u[e] = a, v[e] = b, w[e] = c;
	nex[e] = fir[u[e]], fir[u[e]] = e;
}

int main(){
	init();
	int n, m;
	scanf("%d%d",&n,&m);
	for(int i = 0, a, b, c;i < m;++i){
		scanf("%d%d%d",&a,&b,&c);
		add_edge(a,b,c);
	}
	memset(dp,0x3f,sizeof(dp));
	dp[n] = 0;
	for(int i = n-1;i > 0;i--){
		for(int e = fir[i];~e;e = nex[e]){
			int t = dp[v[e]]+w[e];
			dp[i] = dp[i]>t?t:dp[i];
		}
	}
	printf("%d\n",dp[1]);
}


/*
12 21
1 2 9
1 3 7
1 4 3
1 5 2
2 6 4
2 7 2
2 8 1
3 6 2
3 7 7
4 8 11
5 7 11
5 8 8
6 9 6
6 10 5
7 9 4
7 10 3
8 10 5
8 11 6
9 12 4
10 12 2
11 12 5
*/
