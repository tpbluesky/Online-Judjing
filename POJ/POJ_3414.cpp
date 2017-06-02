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
const int maxm = 20005;
int a, b, c, vis[maxn][maxn]; 
int pre[maxm], head, rear;
struct node{
	int x, y ,step, op;
	node(){}
	node(int xx,int yy,int stepp){
		x = xx; y = yy; step = stepp;
		op = 0;
	}
}Q[maxm];

void check(node t,int op){
//	cout<<op<<" "<<t.x<<" "<<t.y<<endl;
	t.op = op;
	t.step++;
	if(!vis[t.x][t.y]){
		pre[rear] = head-1;
		Q[rear++] = t;
		vis[t.x][t.y] = 1;
	}
} 

char s[][30] = {"FILL(1)\n","FILL(2)\n","DROP(1)\n","DROP(2)\n","POUR(1,2)\n","POUR(2,1)\n"};

void output(int pos){
	if(pre[pos] == -1){
		printf(s[Q[pos].op-1]);
		return;
	}
	output(pre[pos]);
	printf(s[Q[pos].op-1]);
}

int bfs(){
	head = 0, rear = 0;
	Q[rear++] = {0,0,0};
	vis[0][0] = 1;
	memset(pre,-1,sizeof(pre));
	while(head < rear){
		node t = Q[head++];
//		cout<<"----"<<t.x<<" "<<t.y<<" "<<t.step<<endl;
		if(t.x == c || t.y == c){
			//do output
			printf("%d\n",t.step);
			output(head-1);
			return t.step;
		}
		//fill 1
		node tmp = t; 	tmp.x = a;	check(tmp,1);
		//fill 2 
		tmp = t; 	tmp.y = b;	check(tmp,2);
		//drop 1
		tmp = t; 	tmp.x = 0;	check(tmp,3);
		//drop 2
		tmp = t; 	tmp.y = 0;	check(tmp,4);
		//swap 1, 2
		tmp = t; 
		if(b-tmp.y >= tmp.x){
			tmp.y += tmp.x;
			tmp.x = 0;
		}else{
			tmp.x -= (b-tmp.y);
			tmp.y = b;
		}
		check(tmp,5);
		//swap 2 1
		tmp = t; 
		if(a-tmp.x >= tmp.y){
			tmp.x += tmp.y;
			tmp.y = 0;
		}else{
			tmp.y -= (a-tmp.x);
			tmp.x = a;
		}
		check(tmp,6);
	}
	return -1;
}

int main(){
	while(scanf("%d%d%d",&a,&b,&c) ==3){
		memset(vis,0,sizeof(vis));
		int ans = bfs();
		if(ans == -1){
			printf("impossible\n");
		}
	}
    return 0;
}


