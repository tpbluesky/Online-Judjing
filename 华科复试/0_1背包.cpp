#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxn = 105;

int w[maxn], n, m;

int kmap(int left,int p){
	if(left < 0 || p < 0){
		return 0;
	}
	if(w[p] == left) {
		return 1;
	}else if(w[p] < left){
		return kmap(left-w[p],p-1)||kmap(left,p-1);
	}else{
		return kmap(left,p-1);
	}
}


int solve(int left,int p){
	if(left == 0){
		return p>=-1;
	}
	if(left < 0 || p < 0) return 0;
	return solve(left-w[p],p-1)+solve(left,p-1);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;++i)
		scanf("%d",&w[i]);
	printf(kmap(m,n-1)?"YES\n":"NO\n");
	printf("%d\n",solve(m,n-1));
} 
