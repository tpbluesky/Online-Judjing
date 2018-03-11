#include <stdio.h>

void q_sort(int *a,int low,int high){
	if(low >= high) return;
	int l = low,h = high;
	int x = a[low], t;
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
	int a[105], n;
	scanf("%d",&n);
	for(int i = 0;i < n;++i)
		scanf("%d",&a[i]);
	q_sort(a,0,n-1);
	for(int i = 0;i < n;++i){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
