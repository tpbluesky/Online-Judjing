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

const int maxn = 35;

struct node{
	int x, y, z, step;
	int operator==(const node &n) const{
		return n.x == x && n.y == y && n.z == z;
	}
}st, end;

char mp[maxn][maxn][maxn];
int vis[maxn][maxn][maxn],x , y, z;

int dz[] = {1,-1,0,0,0,0};
int dx[] = {0,0,1,-1,0,0};
int dy[] = {0,0,0,0,1,-1};

bool isok(int tx,int ty ,int tz){
	if(tx < 0 || ty < 0 || tz < 0 || tx >= x || ty >= y || tz >= z || mp[tz][tx][ty] == '#') return false;
	return  true;
}

int bfs(){
	queue<node> Q;
	Q.push(st);
	while(!Q.empty()){
		node t = Q.front();
		Q.pop();
//		cout<<t.z<<" "<<t.x<<" "<<t.y<<" "<<t.step<<endl;
		if(t == end) return t.step;
		for(int i = 0;i < 6;++i){
			int tx = t.x+dx[i];
			int ty = t.y+dy[i];
			int tz = t.z+dz[i];
//			cout<<"    "<<tz<<" "<<tx<<" "<<ty<<endl;
			if(isok(tx,ty,tz) && !vis[tz][tx][ty]){
				node tp;
				tp.x = tx; tp.y = ty; tp.z = tz; tp.step = t.step+1;
				Q.push(tp);
				vis[tz][tx][ty] = 1;
			}
		}
	}
	return -1;
}

int main(){
	while(scanf("%d%d%d",&z,&x,&y) == 3 && z){
		for(int i = 0;i < z;++i){
			for(int j = 0;j < x;++j){
				scanf("%s",mp[i][j]);
				for(int k = 0;k < y;++k){
					if(mp[i][j][k] == 'S')
						st.x = j, st.y = k, st.z = i, st.step = 0;
					if(mp[i][j][k] == 'E')
						end.x = j, end.y = k, end.z = i;
				}
			}
		}
		memset(vis,0,sizeof(vis));
		int res = bfs();
		printf(res==-1?"Trapped!\n":"Escaped in %d minute(s).\n",res);
	}
    return 0;
}

