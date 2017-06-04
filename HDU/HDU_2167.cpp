/*
author: tpbluesky
time:   17/08/15 08:44
Ìâ½â:	×´Ñ¹DP 
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
const int maxn = 16;

int mp[maxn][maxn], n;
int dp[maxn][1<<16];
int sum[maxn][1<<16];
 
vector<int> state;
int calc(int row,int s)
{
	int res = 0 ;
	for(int i = 0;i < n;++i)
		if(s&(1<<i))
			res += mp[row][i];
	return res;
}
int main()
{
	char c;
	while(scanf("%d%c",&mp[0][0],&c) == 2)
	{
		state.clear();
		n = 1;
		while(scanf("%d%c",&mp[0][n++],&c))
			if(c == '\n')
				break;
		for(int i = 1;i < n;++i)
			for(int j = 0;j < n;++j)
				scanf("%d",&mp[i][j]);	
				
		for(int i = 0;i < (1<<n);++i)
			if((i&(i<<1)) == 0)
				state.push_back(i);	
		int m = state.size();
		
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		
		for(int i = 0;i < n;++i)
			for(int j = 0;j < m;++j)
				sum[i][j] = calc(i,state[j]); 
		
		for(int i = 0;i < m;++i)
			dp[0][i] = sum[0][i];
			
		for(int i = 1;i < n;++i)
			for(int j = 0;j < m;++j)
				for(int k = 0;k < m;++k)
				{
					if(state[j]&state[k])	continue;
					if(state[j]&(state[k]<<1)) continue;
					if(state[j]&(state[k]>>1)) continue;
					dp[i][j] = max(dp[i][j],dp[i-1][k]+sum[i][j]);
				}
		int ans = -inf;
		for(int i = 0;i < m;++i)
			ans = max(ans,dp[n-1][i]);
		printf("%d\n",ans);		
	}
    return 0;
}


