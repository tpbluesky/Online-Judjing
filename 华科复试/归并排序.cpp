#include <stdio.h>

int b[105];

void merge(int a[],int low,int mid,int high){
	int i = low, j = mid+1, k = low;
	while(i <= mid && j <= high){
		if(a[i] < a[j]) b[low++] = a[i++];
		else b[low++] = a[j++];
	} 
	while(i <= mid) b[low++] = a[i++];
	while(j <= high) b[low++] = a[j++];
	for(int p = k;p <= high;++p) a[p] = b[p];
}

void merge_sort(int a[],int low,int high){
	if(low >= high) return;
	int mid = (low+high)>>1;
	merge_sort(a,low,mid);
	merge_sort(a,mid+1,high);
	merge(a,low,mid,high);
}

int main(){
	int a[105], n;
	scanf("%d",&n);
	for(int i = 0;i < n;++i)
		scanf("%d",&a[i]);
	merge_sort(a,0,n-1);
	for(int i = 0;i < n;++i)
		printf(i == n-1?"%d\n":"%d ",a[i]); 
	return 0;
}
