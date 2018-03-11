#include <stdio.h>
#include <string.h>

typedef struct student{
	int age, score;
	char name[105];
}Stu;

Stu stu[1005];
int n;

bool cp(Stu a,Stu b){
	if(a.score > b.score) return 1;
	else if(a.score < b.score) return 0;
	else{
		int t = strcmp(a.name,b.name);
		if(t > 0) return 1;
		else if (t < 0) return 0;
		else{
			return a.age > b.age; 
		}
	}
}

void sort(int low,int high){
	if(low >= high) return;
	Stu x = stu[low];
	int l = low , h = high;
	while(l < h){
		while(l < h && cp(stu[h],x)) h--;
		if(l < h) stu[l++] = stu[h]; 
		while(l < h && cp(x,stu[l])) l++; 
		if(l < h) stu[h--] = stu[l];
	}
	stu[l]= x;
	sort(low,l-1);
	sort(l+1,high);
}

int main(){
	scanf("%d",&n);
	for(int i = 0;i < n;++i)
		scanf("%s%d%d",stu[i].name,&stu[i].age,&stu[i].score);
	sort(0,n-1);
	for(int i = 0;i < n;++i)
		printf("%s %d %d\n",stu[i].name,stu[i].age,stu[i].score);
	return 0;
}
