#include <stdio.h>
#include <string.h>

int a[4][5];

int main(){
	for(int i = 0;i < 4;++i)
		for(int j = 0;j < 5;++j)
			scanf("%d",&a[i][j]);
	int ans[2][5];
	for(int i = 0;i < 5;++i){
		int mt = 0;
		for(int j = 0;j < 4;j++)
			if(a[j][i] > mt){
				mt = a[j][i];
				ans[0][i] = j;
			}
		int st = 0;
		for(int j = 0;j < 4;j++){
			if(j != ans[0][i] && a[j][i] > st){
				st = a[j][i];
				ans[1][i] = j;
			}
		}
		if(ans[0][i] > ans[1][i]){
			int tmp = ans[0][i];
			ans[0][i] = ans[1][i];
			ans[1][i] = tmp;
		}
	}
	for(int i = 0;i < 2;++i)
		for(int j = 0;j < 5;j++)
			printf(j == 4?"%d\n":"%d ",a[ans[i][j]][j]);
	return 0;
}
