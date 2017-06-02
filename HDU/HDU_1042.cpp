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

const int maxn = 10000;

struct BigInt{
	const static int mod = 10000;
	const static int DLEN =4;
	int a[maxn], len;
	
	BigInt(){
		memset(a,0,sizeof(a));
		len = 1;
	}
	
	BigInt(int v){
		memset(a,0,sizeof(a));
		len = 0;
		do{
			a[len++] = v%mod;
			v /= mod;
		}while(v);
	}
	
	BigInt operator*(const BigInt &b) const{
		BigInt res;
		for(int i = 0;i < len;++i){
			int up = 0;
			for(int j = 0;j < b.len;++j){
				int temp = a[i]*b.a[j]+res.a[i+j]+up;
				res.a[i+j] = temp%mod;
				up = temp/mod;
			}
			if(up != 0)
				res.a[i+b.len] = up;
		}
		res.len = len+b.len;
		while(res.a[res.len-1] == 0 && res.len > 1) res.len--;
		return res;
	}
	
	void output(){
		printf("%d",a[len-1]);
		for(int i = len-2;i >= 0;i--)
			printf("%04d",a[i]);
		printf("\n");
	}
};

int main(){

	int n;
	while(scanf("%d",&n) == 1){
		BigInt ans = 1;
		for(int i = 1;i <= n;++i)
			ans = ans*i;
		ans.output();
//		cout<<ans.len<<endl;
	}
    return 0;
}


