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
int dp[1000005];
int s[1000005];
int main()
{
    int n,m;
    int v[105],c[105];
    while(scanf("%d%d",&n,&m)==2)
    {
        if(!n && !m) break;
        for(int i=1;i<=n;i++)
          scanf("%d",&v[i]);
        for(int i=1;i<=n;i++)
         scanf("%d",&c[i]);
        for(int i=1;i<=m;i++) 
         dp[i]=0;
         dp[0]=1;
         int ans=0;
         int count=0;
        for(int i=1;i<=n;i++)
        {
            for (int k=1; k<=c[i]; k<<=1) {   
              s[++count] = k*v[i];  
               c[i]-= k;  
              }  
             if (c[i] > 0) {  
              s[++count] = c[i]*v[i];  
            }  
        }
       for(int i=1;i<=count;i++)  
        {  
            for(int j = m;j>=s[i];j--)  
            {  
                if(!dp[j] && dp[j-s[i]] )  
                {  
                    dp[j] = 1;  
                    ans++;  
                }  
            }  
        }  
        
    printf("%d\n",ans);
    } 
    return 0;
}