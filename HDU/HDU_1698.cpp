/*
author: tpbluesky
time:   2015年8月11日20:50:27 
题解:	
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
void built(int le,int ri,int rt)
{
	if(le == ri){
		tree[rt] = 1;
		return;
	}
	int mid = (le+ri)>>1;
	built(lson);
	built(rson);
	tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}

void pushdown(int rt,int m)
{
	if(col[rt])
	{
		tree[rt<<1] = (m-(m>>1))*col[rt];
		tree[rt<<1|1] = (m>>1)*col[rt];
		col[rt<<1] = col[rt<<1|1] = col[rt];
		col[rt] = 0;
	}
}

void update(int le,int ri,int rt,int x,int y,int val)
{
	if(x <= le && y >= ri)
	{
		col[rt] = val;
		tree[rt] = (ri-le+1)*val;
		return;
	}
	pushdown(rt,ri-le+1);
	int mid = (le+ri)>>1;
	if(x <= mid)
		update(lson,x,y,val);
	if(y > mid)
		update(rson,x,y,val);
		
	tree[rt] = tree[rt<<1]+tree[rt<<1|1];
} 

int main()
{
	int T, n, q, cas = 1;
	cin>>T;
	while(T--)
	{
		memset(col,0,sizeof(col));
		scanf("%d",&n);
		built(1,n,1);
		scanf("%d",&q);
		int a, b, c;
		for(int i = 0;i < q;++i)
		{
			scanf("%d%d%d",&a,&b,&c);
			update(1,n,1,a,b,c);
		}
		printf("Case %d: The total value of the hook is %d.\n",cas++,tree[1]);
	}
    return 0;
}


