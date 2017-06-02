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

const int maxn = 100005;

int a[maxn], n; 
set<int> se;

int main(){

	int T_T;
	scanf("%d",&T_T);
	while(T_T--){
		scanf("%d",&n);
		for(int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
		}
		int ans = 0;
		se.clear();
		se.insert(a[1]);
		for(int i = 2;i <= n;++i){
			while(se.find(a[i]) == se.end()){
				se.insert(a[i++]);
				if(i > n) break;
			}
//			cout<<i<<" "<<se.size()<<endl;
			ans++;
			se.clear();
			se.insert(a[i]);
		}
		printf("%d\n",ans);
	}
    return 0;
}


