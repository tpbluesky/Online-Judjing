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
char s[maxn];
int main(){
	while(~scanf("%s",s)){
		if(strcmp(s,"0") == 0)
			break;
		int len = strlen(s);
		int sum = 0;
		for(int i = 0;i < len;++i){
			sum += s[i]-'0';
			sum %= 9;
		}
		printf(sum==0?"9\n":"%d\n",sum);
	} 
    return 0;
}


