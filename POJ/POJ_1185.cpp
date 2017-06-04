/*
author: tpbluesky
time:   17/08/15 15:14
���:	״ѹDP��dp[i][j][p]��ʾ��i��״̬Ϊs[j],i-1��״̬Ϊs[p],��ʼ������ֵΪ-1����ʾ�޷�����
		dp[0][j][0]Ϊ��ʼ״̬������dfs�����dp[i][j][p] = max(dp[i-1][p][q]+sum[j]),q�����i-2�е�״̬s[q],sum[j]����״̬s[j]��1�ĸ���
		�����ʱ��P��Ӧ��������0��H��Ӧ��1,ֻҪ s[j]&mp[i] != 0�����ų��ߵ�Ӱ���״̬ 
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
const int maxn = 105;
int mp[maxn];
int dp[maxn][maxn][maxn];
int s[maxn*10], sum[maxn*10];
int n, m;

int calc(int s)
{
	int res = 0;
	for(int i = 0;i < m;++i)
		if(s & (1<<i))
			res++;
	return res;	
}

int main()
{
	while(scanf("%d%d",&n,&m) == 2)
	{
		char ch;
		getchar();
		memset(mp,0,sizeof(mp));
		memset(dp,-1,sizeof(dp));
		for(int i = 0;i < n;++i)
			for(int j = 0;j <= m;++j){
				scanf("%c",&ch);
				if(ch == 'H')
					mp[i] |= (1<<j);
			}
		int k = 0;
		for(int i = 0;i < (1<<m);++i)
			if(!(i&(i<<1)) && !(i&(i<<2)))
				s[k] = i, sum[k++] = calc(i);
		for(int i = 0;i < k;++i)
			if(!(s[i]&mp[0]))
				dp[0][i][0] = sum[i];
		for(int i = 1;i < n;++i)
			for(int j = 0;j < k;++j)
				if(!(s[j]&mp[i]))
					for(int p = 0;p < k;++p)
						if(!(s[j]&s[p]))
							for(int q = 0;q < k;++q)
								if(!(s[p]&s[q]) && !(s[q]&s[j]))
								{
									if(dp[i-1][p][q] == -1)
										continue;
									dp[i][j][p] = max(dp[i][j][p],dp[i-1][p][q]+sum[j]);
								}
		int ans = 0;
		for(int i = 0;i < k;++i)
			for(int j = 0;j < k;++j)
				ans = max(ans,dp[n-1][i][j]);
		printf("%d\n",ans);
	}
    return 0;
}


