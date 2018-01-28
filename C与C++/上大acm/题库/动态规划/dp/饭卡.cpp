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
int cmp(int a,int b)
{
    return a<b;
}
int main()
{
    int n;
    int jia[1005];
    int m;
    int dp[1005];
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&jia[i]);
        }
        cin>>m;
        if(m<5) 
        {printf("%d\n",m);continue;}
        sort(jia+1,jia+n+1,cmp);
        clr(dp,0);
        for(int i=1;i<n;i++)
        {
            for(int j=m-5;j>=jia[i];j--)
            {
                dp[j]=max(dp[j],dp[j-jia[i]]+jia[i]);
            }
        }
        printf("%d\n",m-dp[m-5]-jia[n]);          
    }
    return 0;
}