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
	int n, m;
	while(~scanf("%d%d",&n,&m)){
		printf(__gcd(n,m)==1?"%10d%10d    Good Choice\n\n":"%10d%10d    Bad Choice\n\n",n,m);
	}

    return 0;
}


