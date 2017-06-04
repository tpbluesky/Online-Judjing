/*
author: tpbluesky
time: 	14/08/15 09:54 
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
#define lson le,mid,rt<<1
#define rson mid+1,ri,rt<<1|1 
using namespace std;
typedef long long ll;
const int maxn = 100005;
int tree[maxn<<2], col[maxn<<2];

void pushdown(int rt,int m)
{
	if(col[rt])
	{
		tree[rt<<1] += (m-(m>>1))*col[rt];
		tree[rt<<1|1] += (m>>1)*col[rt];
		col[rt<<1] += col[rt];
		col[rt<<1|1] += col[rt];
		col[rt] = 0;
	}
	
}

void update(int le,int ri,int rt,int x,int y)
{
	if(x <= le && y >= ri)
	{
		tree[rt] += (ri-le+1);
		col[rt] += 1;
		return;
	}
	pushdown(rt,ri-le+1);
	int mid = (le+ri)>>1;
	if(x <= mid)
		update(lson,x,y);
	if(y > mid)
		update(rson,x,y);
	tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}

int query(int le,int ri,int rt,int pos)
{
	if(le == ri)
		return tree[rt];
	pushdown(rt,ri-le+1);
	int mid = (le+ri)>>1;
	int ans = 0;
	if(pos <= mid)
		ans = query(lson,pos);
	else
		ans = query(rson,pos);
	tree[rt] = tree[rt<<1]+tree[rt<<1|1];
	return ans;
}

int main()
{
	int n;
	while(scanf("%d",&n) == 1 && n)
	{
		int a, b;
		memset(tree,0,sizeof(tree));
		memset(col,0,sizeof(col));
		for(int  i = 0;i < n;++i)
		{
			scanf("%d%d",&a,&b);
			update(1,n,1,a,b);
		}
		for(int i = 1;i <= n;++i)
			printf(i == n?"%d\n":"%d ",query(1,n,1,i));
	}
    return 0;
}


