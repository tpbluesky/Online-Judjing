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
#define lson le,mid,rt<<1
#define rson mid+1,ri,rt<<1|1
using namespace std;
typedef long long ll;
const int maxn = 200005;
int h, w, n;
int tree[maxn<<2];

void built(int le,int ri,int rt)
{
	tree[rt] = w;
	if(le == ri)
		return;
	int mid = (le+ri)>>1;
	built(lson);
	built(rson);
}
 
int query(int le,int ri,int rt,int val)
{
	if(le == ri)
	{
		tree[rt] -= val;
		return le;
	}
	int mid = (le+ri)>>1;
	int pos = -1;
	if(tree[rt<<1] >= val)
		pos = query(lson,val);
	else 
		pos = query(rson,val);
	tree[rt] = max(tree[rt<<1],tree[rt<<1|1]);
	return pos;
}

int main()
{
	while(scanf("%d%d%d",&h,&w,&n) == 3)
	{
		h = min(h,n);
		built(1,h,1);
		int a; 
		for(int i = 1;i <= n;++i)
		{
			scanf("%d",&a);
			if(a > tree[1])
			{
				puts("-1");
				continue;
			}
			cout<<query(1,h,1,a)<<endl;	
		}
	} 
    return 0;
}


