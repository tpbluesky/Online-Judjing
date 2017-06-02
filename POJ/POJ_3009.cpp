#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 25;

int mp[maxn][maxn];
int sx, sy, ex, ey;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int ans, w, h;
void dfs(int x,int y, int s){
	if(s >= 10)
		return;
	for(int i = 0;i < 4;++i){
		int flag = 1, tx, ty;
		for(int j = 1;;++j){
			tx = x + j*dx[i], ty = y + j*dy[i];
			if(tx <= 0 || ty <= 0 || tx > h || ty > w){
				flag = 0;
				break;
			}
			if(j == 1 && mp[tx][ty] == 1){
				flag = 0;
				break;
			}
			if(mp[tx][ty] == 3){
				ans = min(ans,s+1);
				return;
			}
			if(mp[tx][ty] == 1)
				break;
		}
		if(flag){
			mp[tx][ty] = 0;
			dfs(tx-dx[i],ty-dy[i],s+1);
			mp[tx][ty] = 1;
		}
	}
}

int main(){
	while(scanf("%d%d",&w,&h) == 2 && w){
		ans = inf;
		for(int i = 1;i <=  h;++i)
			for(int j = 1;j <= w;++j){
				scanf("%d",&mp[i][j]);
				if(mp[i][j] == 2)
					sx = i, sy = j;
				if(mp[i][j] == 3)
					ex = i, ey = j;
			}
		dfs(sx, sy, 0);
		printf(ans > 10?"-1\n":"%d\n",ans);
	}	
    return 0;
}
