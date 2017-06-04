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
const int maxn = 12;

ll dp[maxn][1<<12];
int h, w;
ll x;

void dfs(int i,int p,int s)
{
	if(p == w)
	{
		dp[i][s] += x;
		return;
	}
	if(p+2 <= w && !(s&(1<<p)) && !(s&(1<<(p+1))))
		dfs(i,p+2,s|(1<<p)|(1<<(p+1)));
	dfs(i,p+1,s);
}

int main()
{
	while(scanf("%d%d",&h,&w) == 2)
	{
		if(!h && !w)
			break;
		memset(dp,0,sizeof(dp));
		x = 1;
		dfs(1,0,0);
		int k = 1<<w;
		for(int i = 2;i <= h;++i)
			for(int j = 0;j < k;++j)
			{
				if(dp[i-1][j])
				{
					x = dp[i-1][j];
					dfs(i,0,j^(k-1));
				}
			}
		cout<<dp[h][k-1]<<endl;
	}
    return 0;
}


