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

const int maxn = 20;

int m, n, minans;
int mp[maxn][maxn], tmp[maxn][maxn], ans[maxn][maxn], res[maxn][maxn];

void change(int x,int y){
	mp[x][y] = (mp[x][y]+1)%2;
	mp[x-1][y] = (mp[x-1][y]+1)%2;
	mp[x+1][y] = (mp[x+1][y]+1)%2;
	mp[x][y-1] = (mp[x][y-1]+1)%2;
	mp[x][y+1] = (mp[x][y+1]+1)%2;
}

int main(){
	while(scanf("%d%d",&m,&n) == 2){
		memset(ans,0,sizeof(ans));
		for(int i = 1;i <= m;++i)
			for(int j = 1;j <= n;++j)
				scanf("%d",&tmp[i][j]);
		minans = inf;
		for(int i = 0;i < 1<<n;++i){
			memset(res,0,sizeof(res));
			memcpy(mp,tmp,sizeof(tmp));
			int cnt = 0;
//			cout<<i<<"  ";
			for(int j = 0;j < n;j++){
//				cout<<((i>>j)&1);
				if((i>>j)&1){
					res[1][n-j] = 1;
					change(1,n-j);
					cnt++;
				}
			}
//			cout<<endl;
			for(int j = 2;j <= m;++j){
				for(int k = 1;k <= n;++k){
					if(mp[j-1][k]){
//						cout<<j-1<<" "<<k<<endl;
						res[j][k] = 1;
						change(j,k);
						cnt++;
					}
				}						
			}
			int isok = 1;
			for(int j = 1;j <= n;++j){
				if(mp[m][j]){
					isok = 0;
					break;
				}
			}
			if(isok && cnt < minans){
				memcpy(ans,res,sizeof(res));
				minans = cnt;
			}
		}
		if(minans >= inf){
			printf("IMPOSSIBLE\n");
			continue;
		}
		for(int i = 1;i <= m;++i)
			for(int j = 1;j <= n;++j){
				printf(j == n?"%d\n":"%d ",ans[i][j]);
			} 
	}
    return 0;
}


