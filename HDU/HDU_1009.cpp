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

const int maxn = 1005;

struct node{
	int a, b;
	double rate;
	node(){
	}
	node(int aa,int bb){
		a = aa;
		b = bb;
		rate = (double)a/b;
	}
	
	int operator<(const node t){
		return rate>t.rate;
	}
}; 

node v[maxn];
int m, n;

int main(){
	while(~scanf("%d%d",&m,&n) && ~m && ~n){
		for(int i = 0,a,b;i < n;++i){
			scanf("%d%d",&a,&b);
			v[i] = node(a,b);
		}
		sort(v,v+n);
//		cout<<v[0].a<<" "<<v[0].b<<endl;
		double ans = 0;
		for(int i = 0;i < n && m > 0;++i){
			if(m >= v[i].b){
				ans += v[i].a;
				m -= v[i].b;
			}else{
				ans += m*v[i].rate;
				m = 0;
			}
		}
		printf("%.3lf\n",ans);
	}	
    return 0;
}


