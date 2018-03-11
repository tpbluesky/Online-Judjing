#include <stdio.h>

void q_sort(int a[],int low,int high){
	if(low >= high) return;
	int l = low, h = high, x = a[low];
	while(l < h){
		while(l < h && a[h] > x) h--;
		if(l < h) a[l++] = a[h];
		while(l < h && a[l] < x) l++;
		if(l < h) a[h--] = a[l];
	}
	a[l] = x;
	q_sort(a,low,l-1);
	q_sort(a,l+1,high);
}

int main(){
	int n, a[1005];
	scanf("%d",&n);
	int maxa = -1, pos = -1;
	for(int i = 0;i < n;++i){
		scanf("%d",&a[i]);
		if(a[i] > maxa){
			maxa = a[i];
			pos = i;
		}
	} 
	for(int i = pos+1;i < n;++i)
		a[i-1] = a[i]; 
	q_sort(a,0,n-2);
	printf("%d\n",maxa);
	if(n == 1){
		printf("-1\n");
		return 0;
	}
	for(int i = 0;i < n-1;++i)
		printf(i == n-2?"%d\n":"%d ",a[i]);
} 
