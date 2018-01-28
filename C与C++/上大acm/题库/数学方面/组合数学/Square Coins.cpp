#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
ll dp[130];
void init ()
{
    clr(dp,0);
    dp[0]=1;
    for(int i=1;i<=120;i++)
    {
        for(int j=i;j<=120;j++)
        {
            dp[j]+=dp[j-i];
        }
    }
}
    
int main()
{
    int n;
    init();
    while(scanf("%d",&n)==1  && n)
     {
        printf("%lld\n",dp[n]);
     }
    return 0;
}