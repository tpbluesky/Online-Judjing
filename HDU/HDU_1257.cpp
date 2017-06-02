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

const int maxn = 10005;
int a[maxn], n; 

int main(){
	while(scanf("%d",&n) == 1){
		for(int i = 0;i < n;++i)
			scanf("%d",&a[i]);
		int ans = 0;
		for(int i = n-1;i >= 0;i--){
			if(a[i] == -1) continue;
			ans++;
			int d = a[i];
//			cout<<d<<" "; 
			for(int j = i-1;j >= 0;j--){
				if(a[j] == -1) continue;
				if(a[j] >= d) {
					d = a[j];
//					cout<<d<<" ";
					a[j] = -1;
				}
			}
//			cout<<endl;
		}
		printf("%d\n",ans);
	}
    return 0;
}


