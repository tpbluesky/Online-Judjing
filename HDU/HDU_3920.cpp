/*
author: tpbluesky
time:   18/08/15 19:37
题解:	状压DP 
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
double dp[1<<20];
int  n;
double mp[20][20];

struct point
{
	double x, y;
	double distant(const point & p) const 
	{
		return sqrt(sqr(x-p.x)+sqr(y-p.y));
	}
	void read()
	{
		scanf("%lf%lf",&x,&y);
	}
}P[20], st;

int main()
{
	int T, cas = 1;
	cin>>T;
	while(T--)
	{
		int cnt = 0;
		st.read();
		scanf("%d",&n);
		n *= 2;
		for(int i = 0;i < (1<<n);++i)
			dp[i] = inf;
		for(int i = 0;i < n;++i)
			P[i].read();
		memset(mp,0,sizeof(mp));
		for(int i = 0;i < n;++i)
			for(int j = 0;j < n;++j)
			{
				if(i != j)
					mp[i][j] = P[i].distant(st)+P[i].distant(P[j]);
			}
		dp[0] = 0;
		for(int k = 0;k < (1<<n);++k)
			if(dp[k] < inf)
			{
				int i;
				for(i = 0;i < n;++i)	//此处处理可以保证每对点只计算一次 
					if(!(k&(1<<i)))
						break;
				for(int j = i+1;j < n;++j)
					if(!(k&(1<<j)))
					{
						int h = (k|(1<<i))|(1<<j);
						double temp = min(mp[i][j],mp[j][i]);
						if(dp[h] > dp[k] + temp)
							dp[h] = temp+dp[k];
					}
			}
		printf("Case #%d: %.2f\n",cas++,dp[(1<<n)-1]);
	}
    return 0;
}


