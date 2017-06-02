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

const int maxn = 1005;

char mp[maxn][maxn];
int vis[maxn][maxn], n, m, f[maxn][maxn];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

struct node{
	int x, y, step;
	node(){}
	node(int xx,int yy,int ss){
		x = xx; y = yy; step = ss;
	}
}jack;

int isok(int tx,int ty){
	if(tx < 0 || tx >= n || ty < 0 || ty >= m || mp[tx][ty] == '#')
		return 0;
	return 1;
}

void bfsf(){
	queue<node> Q;
	memset(f,0x3f,sizeof(f));
	for(int i = 0;i < n;++i)
		for(int j = 0;j < m;++j){
			if(mp[i][j] == 'F'){
				Q.push(node(i,j,0));
				f[i][j] = 0;
			}
		}	
	while(!Q.empty()){
		node t = Q.front();
		Q.pop();
		for(int i = 0;i < 4;++i){
			int tx = t.x+dx[i]; int ty = t.y+dy[i];
			if(isok(tx,ty) && f[tx][ty] > t.step+1){
				f[tx][ty] = t.step+1;
				Q.push(node(tx,ty,t.step+1));
			}
		}
	}
}

int bfsj(){
	queue<node> Q;
	memset(vis,0,sizeof(vis));
	vis[jack.x][jack.y] = 1;
	Q.push(jack);
	while(!Q.empty()){
		node t = Q.front();
		Q.pop();
		if(t.x == 0 || t.y == 0 || t.x == n-1 || t.y == m-1){
			return t.step+1;
		}
		for(int i = 0;i < 4;++i){
			int tx = t.x+dx[i], ty = t.y+dy[i];
			if(isok(tx,ty) && t.step+1 < f[tx][ty] && !vis[tx][ty]){
				vis[tx][ty] = 1;
				Q.push(node(tx,ty,t.step+1));
			}
		}
	}
	return -1;
}

int main(){
	int T_T;
	scanf("%d",&T_T);
	while(T_T--){
		scanf("%d%d",&n,&m);
		for(int i = 0;i < n;++i){
			scanf("%s",mp[i]);
			for(int j = 0;j < m;++j){
				if(mp[i][j] == 'J'){
					jack = node(i,j,0);
				}
			}
		}
		bfsf();	
		int ans = bfsj();
		printf(ans == -1?"IMPOSSIBLE\n":"%d\n",ans);
	}

    return 0;
}


