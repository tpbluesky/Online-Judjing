#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 300;

char s[maxn], ans[maxn];
int n, len, vis[maxn], mp[maxn];

void dfs(int d){
	if(d == len){
		ans[len] = '\0';
		printf("%s\n",ans);
		return;
	}else{
		int visa[maxn];
		memset(visa,0,sizeof(visa));
		for(int i = 0;i < len;++i){
			if(!vis[i] && !visa[mp[i]]){
				vis[i] = 1;	visa[mp[i]] = 1;
				ans[d] = mp[i]%2?'a'+mp[i]/2:'A'+mp[i]/2;
				dfs(d+1);
				vis[i] = 0;
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		len = strlen(s);
		for(int i = 0;i < len;++i){
			mp[i] = (s[i]>='A'&&s[i]<='Z')?(s[i]-'A')*2:(s[i]-'a')*2+1;
		}
		sort(mp,mp+len);
		memset(vis,0,sizeof(vis));
		dfs(0);
	}	
    return 0;
}


