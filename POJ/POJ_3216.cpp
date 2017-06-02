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
const int maxn = 10005;
int isprime[maxn], n, m;
int vis[maxn];

void makePrime(){
	memset(isprime,1,sizeof(isprime));
	isprime[0] = isprime[1] = 0;
	for(int i = 2;i <= 10000;++i){
		if(isprime[i]){
			for(int j = 2;i*j <= 10000;++j){
				isprime[i*j] = 0;
			}
		}
	}
}

int pp[] = {1000,100,10,1};

int change(int x,int pos,int y){
	int p[4];
	for(int i = 0;i < 4;++i){
		p[i] = (x/pp[i])*pp[i];
		x %= pp[i];
	}
	p[pos] = y*pp[pos];
	int tmp = 0;
	for(int i = 0;i < 4;++i){
//		cout<<p[i]<<" ";
		tmp += p[i]; 
	}
//	cout<<endl;
	return tmp;
}

int bfs(){
	queue<pii> Q;
	Q.push(pii(n,0));
	memset(vis,0,sizeof(vis));
	vis[n] = 1;
	while(!Q.empty()){
		pii t = Q.front();
		Q.pop();
		if(t.first == m) return t.second;
		for(int i = 0;i < 4;++i){
			for(int j = i==0?1:0;j <= 9;++j){
				int tmp = change(t.first,i,j);
//				cout<<tmp<<"  "<<i<<" "<<j<<endl;
				if(isprime[tmp] && !vis[tmp]){
					vis[tmp] = 1;
					Q.push(pii(tmp,t.second+1));
				}
			}
		}
	}
	return -1;
}

int main(){
	makePrime();
	int T_T;
	scanf("%d",&T_T);
	while(T_T--){
		scanf("%d%d",&n,&m);
		int ans = bfs();
		printf(ans==-1?"Impossible\n":"%d\n",ans);
	}
    return 0;
}


