#include <stdio.h>
#include <algorithm>
#include <string.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 15;

int mp[maxn][maxn], n, m, d[maxn], vis[maxn], f[maxn];

int prim(){
	memset(vis,0,sizeof(vis));
	for(int i = 1;i <= n;++i){
		d[i] = mp[1][i];
		f[i] = 1;
	}
	vis[1] = 1;
	int res = 0;
	for(int p = 2;p <= n;++p){
		int x = -1, minl = inf;
		for(int i = 1;i <= n;++i){
			if(!vis[i] && d[i] < minl){
				minl = d[i];
				x = i; 
			} 
		}
		vis[x] = 1;
		printf("%d %d %d\n",f[x],x,mp[f[x]][x]);
		res += minl;
		for(int i = 1;i <= n;++i) 
			if(!vis[i]){
				if(d[i] > mp[x][i]){
					d[i] = mp[x][i];
					f[i] = x;
				}
			}
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	memset(mp,0x3f,sizeof(mp));
	for(int i = 0, a, b, c;i < m;++i) {
		scanf("%d%d%d",&a,&b,&c);
		mp[a][b] = mp[b][a] = c;
	}
	printf("%d\n",prim());	
	return 0;
}

/*
6 10
1 2 10
1 4 30
1 5 45
2 3 50
2 5 40
2 6 25
3 5 35
3 6 15
4 6 20
5 6 55 
*/ 
