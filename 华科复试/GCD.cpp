#include <stdio.h>

int gcd(int a,int b){
	return b == 0?a:gcd(b,a%b);
}

int _gcd(int a,int b){
	while(b != 0){
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}

int main(){
	printf("%d\n",_gcd(6 ,4));	
} 
