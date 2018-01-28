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
    ll dp[60];
    dp[0]=0;dp[1]=1;
    for(int i=2;i<60;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
   // for(int i=0;i<=50;i++) printf("%lld\n",dp[i]);
    int T;
    cin>>T;
    while(T--)
    {
        int a,b;
        cin>>a>>b;
        printf("%lld\n",dp[b-a+1]);
    }
     //system("pause");
    return 0;
}
