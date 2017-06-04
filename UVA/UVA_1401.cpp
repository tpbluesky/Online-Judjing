/*
author: tpbluesky
time:   19/08/15 14:52
Ìâ½â:	TireÊ÷ 
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
#define clr(x) memset(x,0,sizeof(x))
using namespace std;
const int mod = 20071027;
typedef long long ll;
struct tire
{
	tire *next[26];
	bool isword;
} *root;

char s[300010], str[105];
int dp[300010], len;

void insert(char *s)
{
	tire *head = root;
	for(int i = 0;s[i] != 0;++i)
	{
		int id = s[i]-'a';
		if(head->next[id] == NULL)
		{
			head->next[id] = new tire();
			head->next[id]->isword = false;
		}
		head = head->next[id];
	}
	head->isword = true;
}

int search(char *s,int k)
{
//	cout<<s<<endl;
	tire *head = root;
	int res = 0;
	for(int i = 0;s[i] != '\0';++i)
	{
		int id = s[i]-'a';
		if(head->next[id] == NULL)
			break;
		if(head->next[id]->isword)
		{
//			cout<<k<<" "<<k+i<<" "<<dp[k]<<" "<<dp[k+i]<<endl;;
//			dp[k] += dp[k+i]; 
			dp[k] = (dp[k+i+1]+dp[k])%mod;
		}
		head = head->next[id];
	}
	return res;
}

void del(tire *head)
{
	for(int i = 0;i < 26;++i)
		if(head->next[i] != NULL)
			del(head->next[i]);
	delete head;
}

int main()
{
	int n, cas = 1;
	while(scanf("%s",s) == 1)
	{
		root = new tire();
		scanf("%d",&n);
		for(int i = 0;i < n;++i)
		{
			scanf("%s",str);
			insert(str);
		}
		len = strlen(s);
		memset(dp,0,sizeof(dp));
		dp[len] = 1;
		for(int i = len-1;i >= 0;i--)
		{
			search(s+i,i);
//			cout<<dp[i]<<endl;
		}
		printf("Case %d: %d\n",cas++,dp[0]);
		del(root);
	}
    return 0;
}

/*
abcd 
4 
a 
b 
cd 
ab
abcd
5
a
b
c
d
cd
*/
