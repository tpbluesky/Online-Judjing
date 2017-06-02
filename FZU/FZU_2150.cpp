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

const int maxn = 15;
char mp[maxn][maxn];
int n, m, vis[maxn][maxn];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

struct node{
	int x, y,step;
	node(){}
	node(int xx,int yy,int ss){
		x = xx; y = yy; step = ss;
	}
};

int isok(int px,int py){
	if(px < 0 || px >= n || py < 0 || py > m || vis[px][py] || mp[px][py] != '#')
		return 0;
	return 1;
}

int bfs(int x1,int y1,int x2,int y2){
	queue<node> Q;
	memset(vis,0,sizeof(vis));
	vis[x1][y1] = vis[x2][y2] = 1;
	Q.push(node(x1,y1,0));
	Q.push(node(x2,y2,0));
	node t;
	while(!Q.empty()){
		t = Q.front();
		Q.pop();
		for(int i = 0;i < 4;++i){
			int tx = t.x+dx[i];int ty = t.y+dy[i];
			if(isok(tx,ty)){
				vis[tx][ty] = 1;
				Q.push(node(tx,ty,t.step+1));
			}
		}
	}
	for(int i = 0;i < n;++i)
		for(int j = 0;j < m;++j)
			if(mp[i][j] == '#' && !vis[i][j])
				return inf;
	return t.step;	
}

int main(){
	int T_T, cas = 0;
	scanf("%d",&T_T);
	while(T_T--){
		scanf("%d%d",&n,&m);
		for(int i = 0;i < n;++i)
			scanf("%s",mp[i]);
		int cnt = 0;
		for(int i = 0;i < n;++i)
			for(int j = 0;j < m;++j)
				if(mp[i][j] == '#') cnt++;
		if(cnt < 3){
			printf("Case %d: 0\n",++cas);
			continue;
		}
		int ans = inf;
		int mm = n*m;
		for(int i = 0;i < mm;++i){
			int x1 = i/m, y1 = i%m;
			if(mp[x1][y1] == '#'){
				for(int j = i+1;j < mm;++j){
					int x2 = j/m, y2 = j%m;
					if(mp[x2][y2] == '#'){
						int res = bfs(x1,y1,x2,y2);
//						cout<<x1<<" "<<y1<<" | "<<x2<<" "<<y2<<" | "<< res<<endl;
						ans = min(ans,res);
					}
				}
			}
		}
		printf(ans == inf?"Case %d: -1\n":"Case %d: %d\n",++cas,ans);
	}
    return 0;
}


