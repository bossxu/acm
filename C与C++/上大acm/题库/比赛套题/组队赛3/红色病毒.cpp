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
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define mod 100
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
const int maxn = 30;
// 知识点分解:找规律

int main()
{
    int t;
    int dp[4][maxn];
    clr(dp,0);
    int P[maxn];
    dp[0][0] = 1;
    for(int i=1; i<=30; i++)
    {
        dp[0][i] = (dp[0][i-1]*2 + dp[1][i-1] + dp[2][i-1]) % 100;
        dp[1][i] = (dp[1][i-1]*2 + dp[0][i-1] + dp[3][i-1]) % 100;
        dp[2][i] = (dp[2][i-1]*2 + dp[0][i-1] + dp[3][i-1]) % 100;
        dp[3][i] = (dp[3][i-1]*2 + dp[1][i-1] + dp[2][i-1]) % 100;
        if(i > 2)
            P[i-3] =dp[0][i];
    }
    while(cin>>t && t)
    {
        ll n;
        int num=0;
        for(int i=1;i<=t;i++)
        {
            cin>>n;
            if(n<3)
            printf("Case %d: %d\n",++num,dp[0][n]);
            else
            printf("Case %d: %d\n",++num,P[(n-3)%20]);
        }
        cout<<endl;
    }
    return 0;
}