/*
author: tpbluesky
time:   2015年8月26日22:00:51
题解:	状压BFS
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

int vis[maxn][maxn][1<<14];		//标记状态 
int mp[maxn][maxn];
int n, m, k;
int lor[] = {0,1,2,3};//up,down,left,right 	此处的方向和下面数组的方向是一致的，便于操作 
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
struct node
{
	int x, y, state, step;
}st;
int pos[10][2];

bool isok(int x,int y,int orx, int ory, int s)
{
	if(x < 1 || y < 1|| x > n || y > m || mp[x][y] == 1)
		return false;
	int t = 3;
	//cout<<"       "<<s<<endl;
	for(int i = 0;i < k;++i)		//此处是还原原来状态的每个点，判断拓展的点是否是蛇身 
	{
		int p = (s>>(i*2))&t; 		//将s的第i*2+1,i*2+2移到末尾，& 011，得到这两位的数，就可以推出方向 
		if(p == 0)	orx -= 1;
		if(p == 1)	orx += 1;
		if(p == 2)  ory -= 1;
		if(p == 3)  ory += 1;
	//	cout<<"        "<<p<<" "<<orx<<" "<<ory<<endl;
		if(x == orx && y == ory)			//点重复，走到了蛇身 
			return false;
	}
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
		if(tp.x == 1 && tp.y == 1){
			res = tp.step;
			break;
		}
		for(int i = 0;i < 4;++i)
		{
			node temp;
			temp.x = tp.x + dx[i], temp.y = tp.y+dy[i], temp.step = tp.step+1, temp.state = (tp.state<<2)|lor[i];  
			int t = (1<<(2*k-2))-1; temp.state &= t;	//上面的右移比较巧妙，可以自己动手模拟一下看看，此处是将temp.state高位全部置为0 
			//cout<<temp.state<<endl;
			if(isok(temp.x, temp.y, tp.x, tp.y, tp.state) && !vis[temp.x][temp.y][temp.state])
			{
				vis[temp.x][temp.y][temp.state] = 1;
				q.push(temp);
			}
		}
	}
	return res;
}

int main()
{
	int cas = 1;
	while(scanf("%d%d%d",&n,&m,&k) == 3)
	{
		memset(mp,0,sizeof(mp));
		if(!n && !m && !k)
			break;
		for(int i = 0;i < k;++i)
		{
			scanf("%d%d",&pos[i][0],&pos[i][1]);
			if(i == 0){
				st.x = pos[i][0], st.y = pos[i][1],st.state = 0, st.step = 0;
			}
		}
		int p;
		scanf("%d",&p);
		for(int i = 0, a, b;i < p;++i)
		{
			scanf("%d%d",&a,&b);
			mp[a][b] = 1;
		}
		for(int i = 1;i < k;++i)			//获取初始状态，不懂得可以手动模拟下 
		{
			int s = 0;
			int tx = pos[i][0]-pos[i-1][0] , ty = pos[i][1]-pos[i-1][1];
			if(tx == -1) s = (s|lor[0])<<(i*2-2); 
			if(tx == 1) s = (s|lor[1])<<(i*2-2);
			if(ty == -1)	s = (s|lor[2])<<(i*2-2);
			if(ty == 1) s = (s|lor[3])<<(i*2-2);
			st.state |= s;
		}
	//	cout<<st.state<<endl;
		printf("Case %d: %d\n",cas++,bfs());
	}
    return 0;
}


