#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 105;
int din[maxn];
int n, m, ans[maxn], cnt;
vector<int> mp[maxn];

void topo(){
	queue<int> q;
	cnt = 0;
	for(int i = 1;i <= n;++i)
		if(!din[i]) q.push(i);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		ans[cnt++] = t;
		for(int i = 0;i < mp[t].size();++i){
			din[mp[t][i]]--;
			if(din[mp[t][i]] == 0)
				q.push(mp[t][i]);
		}
	}
}

int main(){
	while(scanf("%d%d",&n,&m) == 2 && n){
		memset(din,0,sizeof(din));
		for(int i = 0;i <= n;++i)
			mp[i].clear();
		for(int i = 0, a, b;i < m;++i){
			scanf("%d%d",&a,&b);
			din[b]++;
			mp[a].push_back(b);
		}
		topo();
		for(int i = 0;i < cnt;++i)
			printf(i == cnt-1?"%d\n":"%d ",ans[i]);
	}	
    return 0;
}


