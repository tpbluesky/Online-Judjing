#include<stdio.h>
void sort(int a[],int low,int high)
{
	if(low==high) return ;
	int x = a[low],l=low,h=high;
	while(low<high)
	{
		while(a[high]>x&&low<high) high--;
	    if(low<high) a[low++] = a[high];
	
		while(a[low]<x&&low<high) low++;
		if(low<high) a[high--] = a[low];		
	}
	a[high] = x;
	sort(a,l,low-1);
	sort(a,high+1,h);
}
int main()
{
	int a[100],n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,0,n-1);//¿ìËÙÅÅÐò 
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
} 
