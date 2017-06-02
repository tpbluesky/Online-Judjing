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

const int maxn = 105;

struct node{
	int x[3], step;
	node(){}
	node(int x0,int x1,int x2,int s){
		x[0] = x0; x[1] = x1; x[2] = x2; step = s;
	}
};

int n, m, s, vis[maxn][maxn][maxn];  

int isend(node t){
	if(t.x[0] == s/2 && (t.x[1]==s/2 || t.x[2] == s/2))  return 1;
	if(t.x[1] == s/2 && t.x[2] == s/2) return 1;
	return 0;	
}

void swapp(int a,int b,node &t){
	int mb = b==0?n:b==1?m:s;
	if((mb-t.x[b]) >= t.x[a]){
		t.x[b] += t.x[a];
		t.x[a] = 0;
	}else{
		t.x[a] -= (mb-t.x[b]);
		t.x[b] = mb;
	}
}

int bfs(){
	memset(vis,0,sizeof(vis));
	queue<node> Q;
	Q.push(node(0,0,s,0));
	vis[0][0][s] = 1;
	while(!Q.empty()){
		node t = Q.front();
		Q.pop();
		if(isend(t)){
			return t.step;
		}
		for(int i = 0;i < 3;++i)
			for(int j = 0;j < 3;++j)
				if(i != j){
					node tx = t;
					swapp(i,j,tx);
					//cout<<i<<" "<<j<<" "<<tx.x[0]<<" "<<tx.x[1]<<" "<<tx.x[2]<<endl;
					if(!vis[tx.x[0]][tx.x[1]][tx.x[2]]){
						vis[tx.x[0]][tx.x[1]][tx.x[2]] = 1;
						tx.step++; 
						Q.push(tx);
					}
				}
	}
	return -1;
}

int main(){
	while(scanf("%d%d%d",&s,&n,&m) == 3 && s){
		if(s%2 == 1){
			printf("NO\n");
			continue;
		}
		int ans = bfs();
		printf(ans==-1?"NO\n":"%d\n",ans); 
	}
    return 0;
}


