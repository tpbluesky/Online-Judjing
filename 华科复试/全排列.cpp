#include <stdio.h>
#include <string.h>

int vis[105], path[105];
int n;

void dfs(int p){
	if(p == n){
		for(int i = 0;i < n;++i)
			printf(i== n-1?"%d\n":"%d ",path[i]);
		return;
	}
	for(int i = 0;i < n;++i)
		if(!vis[i]){
			vis[i] = 1;
			path[p] = i;
			dfs(p+1);
			vis[i] = 0;
		}
}

int main(){
	scanf("%d",&n);
	memset(vis,0,sizeof(vis));
	dfs(0);
} 
