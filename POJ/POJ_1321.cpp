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

const int maxn = 10;

int y[maxn], n, m, ans;
char mp[maxn][maxn];

void dfs(int row,int left){
	if(left == 0){
		ans++;
		return;
	}
	if(n-row < left)
		return;
	for(int i = 0;i < n;++i){
		if(mp[row][i] == '#' && !y[i]){
			y[i] = 1;
			dfs(row+1,left-1);
			y[i] = 0;
		}
	}
	dfs(row+1,left);
}

int main(){
	
	while(scanf("%d%d",&n,&m) == 2){
		if(n == -1 && m == -1) break;
		memset(y,0,sizeof(y));
		ans = 0;
		for(int i = 0;i < n;++i)
			scanf("%s",mp[i]);
		dfs(0,m);
		printf("%d\n",ans);
	}
	
    return 0;
}


