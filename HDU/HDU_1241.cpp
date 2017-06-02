#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <queue>
#define inf 0x3f3f3f3f
#define eps 1e-8
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;

const int maxn = 105;

char mp[maxn][maxn];
int n, m, vis[maxn][maxn];

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

int isok(int x,int y){
	if(x < 0 || y < 0 || x >= m || y >= n || mp[x][y] != '@' || vis[x][y])
		return 0;
	return 1;
}

void dfs(int x,int y){
	for(int i = 0;i < 8;++i){
		int tx = x+dx[i], ty = y+dy[i];
		if(isok(tx,ty)){
			vis[tx][ty] = 1;
			dfs(tx,ty);
		} 
	}
}

int main(){
	while(scanf("%d%d",&m,&n) && m){
		for(int i = 0;i < m;++i)
				scanf("%s",mp[i]);
		memset(vis,0,sizeof(vis));
		int ans = 0;
		for(int i = 0;i < m;++i)
			for(int j = 0;j < n;++j)
				if(mp[i][j] == '@' && !vis[i][j]){
					dfs(i,j);
					ans++;
				}
		printf("%d\n",ans);
	}
    return 0;
}


