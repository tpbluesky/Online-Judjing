/*
author: tpbluesky
time:   2015��8��26��22:00:51
���:	״ѹBFS
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

int vis[maxn][maxn][1<<14];		//���״̬ 
int mp[maxn][maxn];
int n, m, k;
int lor[] = {0,1,2,3};//up,down,left,right 	�˴��ķ������������ķ�����һ�µģ����ڲ��� 
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
	for(int i = 0;i < k;++i)		//�˴��ǻ�ԭԭ��״̬��ÿ���㣬�ж���չ�ĵ��Ƿ������� 
	{
		int p = (s>>(i*2))&t; 		//��s�ĵ�i*2+1,i*2+2�Ƶ�ĩβ��& 011���õ�����λ�������Ϳ����Ƴ����� 
		if(p == 0)	orx -= 1;
		if(p == 1)	orx += 1;
		if(p == 2)  ory -= 1;
		if(p == 3)  ory += 1;
	//	cout<<"        "<<p<<" "<<orx<<" "<<ory<<endl;
		if(x == orx && y == ory)			//���ظ����ߵ������� 
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
			int t = (1<<(2*k-2))-1; temp.state &= t;	//��������ƱȽ���������Լ�����ģ��һ�¿������˴��ǽ�temp.state��λȫ����Ϊ0 
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
		for(int i = 1;i < k;++i)			//��ȡ��ʼ״̬�������ÿ����ֶ�ģ���� 
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


