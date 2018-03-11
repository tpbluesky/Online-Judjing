#include <stdio.h>
#include <string.h>

int f[105], n, m;

void init(){
	for(int i = 1;i <= n;++i)
		f[i] = i;
}

int fi(int a){
	int x = a;
	while(f[x] != x) x = f[x];
	while(f[a] != x){
		f[a] = x;
		a = f[a];
	}
	return x;	
}

int join(int x,int y){
	int fx = fi(x), fy = fi(y);
	if(fx != fy){
		f[fx] = fy;
	}
}


int main(){
	scanf("%d%d",&n,&m);
	init();
	for(int i = 0, a, b;i < m;++i){
		scanf("%d%d",&a,&b);
		join(a,b);
	}
	int cnt = 0;
	for(int i = 1;i <= n;++i){
		if(fi(i) == i) cnt++;
		printf("%d ",f[i]);
	}
	printf("%d\n",cnt);
} 

/*
6 4
1 2
2 4
3 5
4 6
*/
