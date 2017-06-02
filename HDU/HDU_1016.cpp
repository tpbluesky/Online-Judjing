#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <queue>
#define inf 0x3f3f3f3f
#define eps 1e-8
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;

const int maxn = 250;

int isPrime[maxn];
int ans[25];
int vis[25], n;

void prime_tb(){
	memset(isPrime,1,sizeof(isPrime));
	isPrime[0] = isPrime[1] = 0;
	for(int i = 2;i <= maxn;++i){
		if(isPrime[i]){
			for(int j = 2;j*i < maxn;++j){
				isPrime[i*j] = 0;
			}
		}
	}
}


void dfs(int pos){
	if(pos > n){
		if(isPrime[ans[n]+ans[1]]){
			for(int i = 1;i <= n;++i){
				printf(i == n?"%d\n":"%d ",ans[i]);
			}
		}
	}
	for(int i = 1;i<= n;++i){
		if(!vis[i] && isPrime[i+ans[pos-1]]){
//			cout<<i<<"  "<<i+ans[pos-1]<<endl;
			vis[i] = 1;
			ans[pos] = i;
			dfs(pos+1);
			vis[i] = 0;
		}
	}
}

int main(){
	prime_tb();
	int T_T = 0;
	while(~scanf("%d",&n)){
		memset(vis,0,sizeof(vis));
		ans[1] = 1;
		vis[1] = 1;
		printf("Case %d:\n",++T_T);
		dfs(2);
		printf("\n");
	}
    return 0;
}


