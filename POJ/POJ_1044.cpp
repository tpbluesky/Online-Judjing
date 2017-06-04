/*
author: tpbluesky
time:   
Ã‚Ω‚:
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
const int maxn = 55;

char mp[maxn][maxn];
int vis[maxn][maxn][1<<10];
int w, h, l, m, value[15];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
 
struct node
{
	int x, y, step, state;
}st;

bool isok(int x,int y)
{
	if(x < 0 || y < 0 || x >= h || y >= w || mp[x][y] == '*')
		return false;
	return true;
}

int bfs()
{
	memset(vis,0,sizeof(vis));
	queue<node> q;
	q.push(st);
	vis[st.x][st.y][st.state] = 1;
	int res = -1;
	while(!q.empty())
	{
		node tp = q.front();
		q.pop();
		if(tp.step > l)
			break;
	//	cout<<tp.x<<" "<<tp.y<<" "<<tp.step<<" "<<tp.state<<endl; 
		if(mp[tp.x][tp.y] == '<')
		{
			int ans = 0;
			for(int i = 0;i <= 10;++i)
			{
				if(tp.state&(1<<i))
					ans += value[i];
			}
			res = max(ans,res);
		}
		for(int i = 0;i < 4;++i)
		{
			node temp;
			temp.x = tp.x + dx[i], temp.y = tp.y+dy[i], temp.step = tp.step+1, temp.state = tp.state;
			if(isok(temp.x,temp.y) && !vis[temp.x][temp.y][temp.state])
			{
				vis[temp.x][temp.y][temp.state] = 1;
				if(mp[temp.x][temp.y] >= 'A' && mp[temp.x][temp.y] <= 'J')
				{
					vis[temp.x][temp.y][temp.state] = 0;
					int t = mp[temp.x][temp.y]-'A';
					temp.state |= (1<<t);
					if(!vis[temp.x][temp.y][temp.state])
					{
						vis[temp.x][temp.y][temp.state] = 1;
						q.push(temp);
					}
				}
				else
					q.push(temp);
			}
		}
	}
	return res;
}

int main()
{
	int T, cas = 1;
	cin>>T;
	while(T--)
	{
		if(cas != 1)
			printf("\n");
		scanf("%d%d%d%d",&w,&h,&l,&m);
		for(int i = 0;i < m;++i)
			scanf("%d",&value[i]);
		for(int i = 0;i < h;++i)
		{
			scanf("%s",mp[i]);
			for(int j = 0;j < w;++j)
				if(mp[i][j] == '@')
					st.x = i, st.y = j, st.step = 0,st.state = 0;
		}
		int ans = bfs();
		printf("Case %d:\n",cas++);
		printf(ans==-1?"Impossible\n":"The best score is %d.\n",ans);
	}
    return 0;
}


