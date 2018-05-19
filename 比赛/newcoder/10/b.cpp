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
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int shu[1000005];
int dp[1000005];
int main()
{
   int n;
   while(cin>>n)
   {
     for(int i = 1;i<=n;i++)
     {
       scanf("%d",&shu[i]);
     }
     dp[n] = shu[n];
     for(int i = n-1;i>=1;i--)
     {
       dp[i] = max(dp[i+1],shu[i]);
     }
     int maxn = n;
     stack<int>q;
     int k;
     for(int i = 1;i<=n;i++)
     {
       if(dp[i] == shu[i])
       {
         cout<<shu[i];
         if(!q.empty() || i==n)
         {
           cout<<" ";
         }
       }
       else
       {
         q.push(shu[i]);
       }
     }
     while(!q.empty())
     {
       cout<<q.top();
       q.pop();
       if(q.empty())
       {
         cout<<endl;
       }
       else
       cout<<" ";
     }
   }
  return 0;
}
