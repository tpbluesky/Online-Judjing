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

const int maxn = 10;
int mp[maxn][maxn], vis[maxn][maxn];
int head, rear, pre[100];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

struct node{
	int x, y, step;
	node(){}
	node(int xx,int yy,int s){
		x = xx; y = yy; step = s;
	}
}Q[100];

int isok(int x,int y){
	if(x < 1 || y < 1 || x > 5 || y > 5 || vis[x][y] || mp[x][y] == 1)
		return false;
	return  true;
}

void output(int xx){
	if(pre[xx] == -1){
		printf("(%d, %d)\n",Q[xx].x-1,Q[xx].y-1);
		return;
	}
	output(pre[xx]);
	printf("(%d, %d)\n",Q[xx].x-1,Q[xx].y-1);
}

int bfs(){
	memset(pre,-1,sizeof(pre));
	head = 0, rear = 0;
	Q[rear++] = node(1,1,0);
	vis[1][1] = 1;
	while(head < rear){
		node t = Q[head++];
		if(t.x == 5 && t.y == 5)
		{
			//do output 
			output(head-1);
			return t.step;
		}
		for(int i = 0;i < 4;++i){
			int tx = t.x+dx[i];
			int ty = t.y+dy[i];
			if(isok(tx,ty)){
				vis[tx][ty] = 1;
				pre[rear] = head-1;
				Q[rear++] = node(tx,ty,t.step+1);
			}
		}
	}
	return -1;
}

int main(){
	
	for(int i = 1;i <= 5;++i)
		for(int j = 1; j <= 5;++j)
			scanf("%d",&mp[i][j]);
	memset(vis,0,sizeof(vis));
	bfs();
    return 0;
}



