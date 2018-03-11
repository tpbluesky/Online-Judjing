#include <stdio.h>

void q_sort(int *a,int low,int high){
	if(low >= high) return;
	int x = a[low];
	int l = low, h = high;
	while(l < h){
		while(l < h && a[h] >= x) h--;
		if(l < h) a[l++] = a[h];
		while(l < h && a[l] < x) l++;
		if(l < h) a[h--] = a[l]; 
	}
	a[l] = x;
	q_sort(a,low,l-1);
	q_sort(a,l+1,high);
}

//67 23 43 78 34 90 43 89 12
//43 23 43 78 34 90    89
//43 23 43    34 90 78 89
//43 23 43 34    90 78 89

int main(){
	int n, a[105];
	scanf("%d",&n);
	for(int i = 0;i < n;++i)
		scanf("%d",&a[i]);
	q_sort(a,0,n-1);
	for(int i = 0;i < n;++i)
		printf(i == n-1?"%d\n":"%d ",a[i]);
} 
