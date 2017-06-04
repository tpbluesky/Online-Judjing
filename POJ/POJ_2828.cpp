/*
author: tpbluesky
time:   2015年8月11日09:04:38 
题解:	POJ 2828 Buy Tickets(线段树单点更新) 
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
#define lson le,mid,rt<<1
#define rson mid+1,ri,rt<<1|1
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;
const int maxn = 200005;
int tree[maxn<<2], num[maxn], a[maxn], b[maxn]; 

void pushup(int rt)
{
	tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}

void built(int le,int ri,int rt)
{
	if(le == ri){
		tree[rt] = 1;
		return;
	}
	int mid = (le+ri)>>1;
	built(lson);built(rson);
	pushup(rt);
}

void update(int le,int ri,int rt,int x,int val)
{
	if(le == ri)
	{
		tree[rt] = 0;
		num[le] = val;
		return;
	}
	int mid = (le+ri)>>1;
	if(x <= tree[rt<<1])
		update(lson,x,val);
	else
		update(rson,x-tree[rt<<1], val);
		
	pushup(rt);
}

int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		built(0,n-1,1);
		for(int i = 1;i <= n;++i)
			scanf("%d%d",&a[i],&b[i]);
		for(int i = n;i >= 1;--i)
		{
			update(0,n-1,1,a[i]+1,b[i]);
		}
		for(int i = 0;i < n;++i)
			printf(i == n-1?"%d\n":"%d ",num[i]);
	}
    return 0;
}


