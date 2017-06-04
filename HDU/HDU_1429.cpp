/*
author: tpbluesky
time:	2015年8月16日14:04:48   
题解:	状态压缩 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#define inf 0x3f3f3f3f
#define eps 1e-8
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;
const int maxn = 22;

char mp[maxn][maxn];
int vis[maxn][maxn][1<<10], n, m , t; 
struct node
{
	int x, y, step, state; 
}st;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool isok(int x,int y)
{
	if(x < 1 || y < 1 || x > n ||  y > m || mp[x][y] == '*')
		return false;
	return true;
}

int bfs()
{	
	queue<node> q;
	memset(vis,0,sizeof(vis));
	vis[st.x][st.y][0] = 1;
	q.push(st);
	while(!q.empty())
	{
		node tp = q.front();
		q.pop();
		if(mp[tp.x][tp.y] == '^')
			return tp.step;
		//cout<<"              "<<tp.x<<" "<<tp.y<<" "<<tp.step<<" "<<tp.state<<endl;
		for(int i = 0;i < 4;++i)
		{
			node temp;
			temp.x = tp.x + dx[i], temp.y = tp.y+dy[i], temp.step = tp.step+1, temp.state = tp.state;
			if(isok(temp.x,temp.y) && !vis[temp.x][temp.y][temp.state])
			{
				vis[temp.x][temp.y][temp.state] = 1;
				if(mp[temp.x][temp.y] >= 'A' && mp[temp.x][temp.y] <= 'J')
				{
					int t = mp[temp.x][temp.y] - 'A';
					if(temp.state&(1<<t))
						q.push(temp);
				}
				else if(mp[temp.x][temp.y] >= 'a' && mp[temp.x][temp.y] <= 'j')
				{
					vis[temp.x][temp.y][temp.state]= 0;
					int t = mp[temp.x][temp.y] - 'a';
					temp.state |= (1<<t);
					if(!vis[temp.x][temp.y][temp.state])
					{
						vis[temp.x][temp.y][temp.state] = 1;
						q.push(temp);
					}
				}
				else
				{
					q.push(temp);
				}
			}
		} 
	}
	return -1;
}

int main()
{
	while(scanf("%d%d%d",&n,&m,&t) == 3)
	{
		for(int i = 1;i <=n;++i)
		{
			scanf("%s",mp[i]+1);
			for(int j = 1;j <= m;++j)
			{
				if(mp[i][j] == '@')
					st.x = i, st.y = j, st.state = 0;
			}
		}
		int ans = bfs();
		if(ans == -1 || ans >= t)
			printf("-1\n");	
		else
			printf("%d\n",ans);
	}
    return 0;
}


