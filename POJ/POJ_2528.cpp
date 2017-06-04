/*
author: tpbluesky
time:   14/08/15 13:47
题解:	离散化加线段树成段更新 
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
const int maxn = 200100;

int tree[maxn<<2], col[maxn<<2];
int a[maxn], b[maxn];
vector<int> ve;

void pushdown(int rt)
{
	if(col[rt])
	{
		col[rt<<1] = col[rt<<1|1] = col[rt];
		tree[rt<<1] = tree[rt<<1|1] = col[rt];
		col[rt] = 0; 
	}
}

void update(int le,int ri,int rt,int x,int y,int val)
{
	if(x <= le &&  y >= ri)
	{
		col[rt] = val;
		tree[rt] = val;
		return;
	}
	pushdown(rt);
	int mid = (le+ri)>>1;
	//cout<<le<<' '<<ri<<" "<<mid<<endl;
	if(x <= mid)
		update(le,mid,rt<<1, x, y,val);
	if(y > mid)
		update(mid+1,ri,rt<<1|1,x,y,val);
}

int query(int le,int ri,int rt,int x)
{
	if(le  == ri)
		return tree[rt];
	pushdown(rt);
	int mid = (le+ri)>>1;
	if(x <= mid)
		return query(le,mid,rt<<1,x);
	else
		return query(mid+1,ri,rt<<1|1,x);
}
vector<int> ans;
int main()
{
	int T, n;
	cin>>T;
	while(T--)
	{
		ve.clear();
		ans.clear();
		scanf("%d",&n);
		for(int i = 0;i < n;++i)
		{
			scanf("%d%d",&a[i],&b[i]);
			ve.push_back(a[i]);
			ve.push_back(b[i]);
		}
		sort(ve.begin(),ve.end());
		ve.erase(unique(ve.begin(),ve.end()),ve.end());		//离散化过程 
		int h = ve.size();
		memset(tree,0,sizeof(tree));
		memset(col,0,sizeof(col));
		for(int i = 0;i < n;++i)
		{
			int x = lower_bound(ve.begin(),ve.end(),a[i])-ve.begin();
			int y = lower_bound(ve.begin(),ve.end(),b[i])-ve.begin();
			//cout<<x<<" "<<y<<endl;
			update(0,h-1,1,x,y,i+1);
		}
		for(int i = 0;i < h;++i)
			ans.push_back(query(0,h-1,1,i));
		sort(ans.begin(),ans.end());
		ans.erase(unique(ans.begin(),ans.end()),ans.end());
		printf("%d\n",ans.size());
	}
    return 0;
}


