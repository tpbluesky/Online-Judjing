#include <stdio.h>
#include<iostream>
#include<iostream>
using namespace std;
int m[105];

int main(){
    int a, b, n;
    while(~scanf("%d%d%d",&a,&b,&n)){
        if(a== 0 && b == 0 && n == 0)
            break;
        if(a%7 == 0 && b%7 ==0){
            cout<<(n>2?0:1)<<endl;
            continue;
        }
        m[1] = m[2] = 1;
        for(int i = 3;i < 48;++i){
            m[i] = (a*m[i-1]+b*m[i-2])%7;
        }
        cout<<m[n%48]<<endl;
    }
    return 0;
}
