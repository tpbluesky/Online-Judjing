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
typedef pair<int,int> pii;
const int maxn = 200005;

short vis[maxn];
int n, m;

int isok(int x){
	if(x < 0 || x >= maxn || vis[x])
		return 0;
	return 1;
}

int bfs(){
	queue<pii> Q;
	Q.push(pii{n,0});
	vis[n] = 1;
	while(!Q.empty()){
		pii t = Q.front();
		Q.pop();
		if(t.first == m) return t.second;
		if(isok(t.first-1)){
			Q.push(pii{t.first-1,t.second+1});
			vis[t.first-1] = 1;
		}
		if(isok(t.first+1)){
			Q.push(pii{t.first+1,t.second+1});
			vis[t.first+1] = 1;
		}
		if(isok(t.first*2)){
			Q.push(pii{t.first*2,t.second+1});
			vis[t.first*2] = 1;
		}
	}	
	return -1;
}

int main(){
	while(scanf("%d%d",&n,&m) == 2){
		memset(vis,0,sizeof(vis));
		printf("%d\n",bfs());
	}
    return 0;
}


