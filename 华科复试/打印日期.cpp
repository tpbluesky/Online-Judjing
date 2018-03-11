#include <stdio.h>

bool whatyear(int year){
	return (year%4 == 0 && year%100) || year%400 == 0; 
}

int m[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
	int year, sum;
	scanf("%d%d",&year,&sum);
	int month, day;
	if(whatyear(year)) m[2] = 29;
	for(int i = 0;i <= 12;++i){
		if(sum <= m[i]){
			month = i;
			day = sum;
			break;
		}else sum -= m[i];
	}
	printf("%d-%02d-%02d\n",year,month,day);
	return 0;
}
