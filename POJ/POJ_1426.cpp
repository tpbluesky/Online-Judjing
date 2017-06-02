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

const int maxn = 205;
int ans[maxn], n; 

int dfs(ll x,int len){
	if(len >= 20){
		return 0;
	}
	if(x%n == 0){
		printf("%lld\n",x);
		return 1;
	}
	if(dfs(10*x,len+1) || dfs(10*x+1,len+1))
		return  1;
}

int main(){
	while(scanf("%d",&n) == 1 && n){
		memset(ans,0,sizeof(ans));
		dfs(1,1);
	}
    return 0;
}


