#include <stdio.h>
#include <algorithm>
#include <string.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 15;

int mp[maxn][maxn], n, m, d[maxn], vis[maxn];

void dijkstra(int s){
	for(int i = 1;i <= n;++i){
		d[i] = mp[s][i];
		vis[i] = 0;
	}
	d[s] = 0;
	vis[s] = 1;
	for(int p = 1;p <= n;++p){
		int x = -1, minl = inf;
		for(int i = 1;i <= n;++i)
			if(!vis[i] && d[i] < minl){
				minl = d[i];
				x = i;
			}	
		if(x == -1) break;
		vis[x] = 1;
		for(int i = 1;i <= n;++i){
			if(!vis[i] && mp[x][i] < inf && d[i] > d[x]+mp[x][i]){
				d[i] = d[x]+mp[x][i];
			}
		}
			
	}
	
}

int main(){
	scanf("%d%d",&n,&m);
	memset(mp,0x3f,sizeof(mp));
	for(int i = 0, a, b, c;i < m;++i) {
		scanf("%d%d%d",&a,&b,&c);
		mp[a][b] = c;
	}
	dijkstra(1);
	for(int i = 1;i <= n;++i)	
		printf(i == n?"%d\n":"%d ",d[i]);
	return 0;
}


/*
6 11
1 2 50
1 3 10 
1 5 45
2 3 15
2 5 10
3 1 20
3 4 15
4 2 20
4 5 35
5 4 30
6 4 3 
*/
