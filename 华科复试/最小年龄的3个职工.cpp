#include <stdio.h>
#include <string.h>

struct node{
	int age, id;
	char name[11];
};
node emp[35];

int cp(node a,node b){
	if(a.age == b.age){
		if(a.id ==  b.id){
			return strcmp(a.name,b.name)>0;
		}else return a.id>b.id;
	}else return a.age>b.age;
}

void sort(int low,int high){
	if(low >= high) return;
	node x = emp[low];
	int l = low, h = high;
	while(l < h){
		while(l < h && cp(emp[h],x)) h--;
		if(l < h) emp[l++] = emp[h];
		while(l < h && cp(x,emp[l])) l++;
		if(l < h) emp[h--] = emp[l];
	}
	emp[l] = x;
	sort(low,l-1);
	sort(l+1,high);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;++i)
		scanf("%d%s%d",&emp[i].id,emp[i].name,&emp[i].age);
	sort(0,n-1);
	n = n>=3?3:n;
	for(int i = 0;i < n;++i)
		printf("%d %s %d\n",emp[i].id,emp[i].name,emp[i].age);
}
