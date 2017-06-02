#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <queue>
#define inf 0x3f3f3f3f
#define eps 1e-8
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;

//const int maxn = ;

int main(){
    double ans[10] = {1,2,2.5};
    int tmp[10] = {1,1,2};
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    for(int i = 3;i <= 9;++i){
            tmp[i] = tmp[i-1]*i;
            ans[i] = ans[i-1]+1.0/tmp[i];
            printf("%d %.9lf\n",i,ans[i]);
    }
    return 0;
}
