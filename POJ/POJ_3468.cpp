/*
author: tpbluesky
time:	14/08/15 10:25   
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

ll tree[maxn<<2], col[maxn<<2];

void built(int le,int ri,int rt)
{
	col[rt] = 0;
	if(le == ri)
	{
		scanf("%lld",&tree[rt]);
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
		col[rt<<1] +=  col[rt];
		col[rt<<1|1] += col[rt];
		tree[rt<<1] += (m-(m>>1))*col[rt];
		tree[rt<<1|1] += (m>>1)*col[rt];
		col[rt] = 0;
	}
}

void update(int le,int ri,int rt,int x,int y,ll val)
{
	if(x <= le && y >= ri)
	{
		tree[rt] += (ri-le+1)*val;
		col[rt] += val;
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

ll query(int le,int ri,int rt,int x,int y)
{
	if(x <= le && y >= ri)
		return tree[rt];
	pushdown(rt,ri-le+1);
	int mid = (le+ri)>>1;
	ll ans = 0;
	if(x <= mid)
		ans += query(lson,x,y);
	if(y > mid)
		ans += query(rson,x,y);
	tree[rt] = tree[rt<<1]+tree[rt<<1|1];
	return ans;
}

int main()
{
	int n, m, a, b;
	while(scanf("%d%d",&n,&m) == 2)
	{
		built(1,n,1);
		char s[5];
		for(int i = 0;i < m;++i)
		{
			scanf("%s",s);
			if(s[0] == 'Q'){
				scanf("%d%d",&a,&b);
				printf("%lld\n",query(1,n,1,a,b));
			}
			else{
				ll c;
				scanf("%d%d%lld",&a,&b,&c);
				update(1,n,1,a,b,c);
			}
		}
	}
    return 0;
}

/*
10 20
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
C 3 6 -3
Q 1 10
Q 2 4
*/
