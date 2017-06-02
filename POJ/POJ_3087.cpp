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

const int maxn = 205;

char s1[maxn], s2[maxn], s12[maxn], tmp[maxn];
set<string> se;
int c;

int main(){

	int T_T, cas = 0;
	scanf("%d",&T_T);
	while(T_T--){
		scanf("%d",&c);
		scanf("%s%s%s",s1,s2,s12);	
		se.clear();
		int ans = 0;
		int cnt = 0;
		while(1){
			cnt++;
			for(int i = 0;i < c;++i){
				tmp[2*i] = s2[i];
				tmp[2*i+1] = s1[i]; 
			}
			tmp[2*c] = '\0';
			if(strcmp(tmp,s12) == 0){
				ans = 1;
				break;
			}
			string s = tmp;
			if(se.find(s) != se.end()) break;
			se.insert(s);
				for(int i = 0;i < 2*c;++i){
				if(i < c) s1[i] = tmp[i];
				else s2[i-c] = tmp[i];
			}
//			printf("%s %s %s\n",s1,s2,tmp);
		}
		printf(ans==0?"%d -1\n":"%d %d\n",++cas,cnt);
	}

    return 0;
}


