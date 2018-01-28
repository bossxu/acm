#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;

int main()
{
    char a[3];
    while(scanf("%c%c%c",&a[0],&a[1],&a[2])==3)
    {
        sort(a,a+3);
        getchar();
        printf("%c %c %c\n",a[0],a[1],a[2]);
    }
   return 0;
}