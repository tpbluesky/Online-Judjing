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
	
	//const int maxn = ;
	
	int main(){
		int T_T, n, m;
		scanf("%d",&T_T);
		while(T_T--){
			int cas = 1;
			while(scanf("%d%d",&n,&m) == 2){
				if(n == 0 && m == 0) break;
				int ans = 0;
				for(int i = 1;i < n;++i){
					for(int j = i+1;j < n;++j){
						if((i*i+j*j+m)%(i*j) == 0) ans++;
					}
				}
				printf("Case %d: %d\n",cas++,ans);
			}
			if(T_T != 0)
				printf("\n");
		} 
	    return 0;
	}
	

