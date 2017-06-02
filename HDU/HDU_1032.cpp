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

const int maxn = 1000005;

int i, j;

int a[maxn];

void solve(){
	for(int i = 1;i < 1000000;++i){
		int tmp = 1;
		ll x = i;
		while(x != 1){
			if(x%2) x =3*x+1;
			else x = x/2;
			tmp++;
		}
		a[i] = tmp;
	}
}

int main(){
	solve();
	while(scanf("%d%d",&i,&j) == 2){
		int n = i, m = j;
		if(i > j) swap(i,j);
		int ans = -inf; 
		for(int k = i;k <= j;k++){
			ans = max(ans,a[k]);
		}
		printf("%d %d %d\n",n,m,ans);
	}
    return 0;
}


