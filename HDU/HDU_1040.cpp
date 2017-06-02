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

int a[maxn], n;

int main(){
	int T_T;
	scanf("%d",&T_T);
	while(T_T--){
		scanf("%d",&n);
		for(int i = 0;i < n;++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		for(int i = 0;i < n;++i)
			printf(i != n-1?"%d ":"%d\n",a[i]); 
	}
    return 0;
}


