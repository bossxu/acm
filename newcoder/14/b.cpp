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
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int map[1000005];
int dp[1000005];
bool st[1000005];
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int n,m;
  ll k;
  while(cin>>n>>m>>k)
  {
    clr(st,0);
    clr(dp,0);
     for(int i = 1;i<=n;i++)
     {
       scanf("%d",&map[i]);
     }
     int sum = 0;
     for(int i = n;i>=1;i--)
     {

       if(sum+map[i] > k)
       {
         sum = map[i];
         dp[i] = dp[i+1]+1;
         st[]
       }
       else
       {
         sum+=map[i];
         dp[i] = dp[i+1];
       }
     }
     for(int i =1;i<=m;i++)
     {
       int a,b;
       scanf("%d%d",&a,&b);
       int o = dp[a]-dp[b]-1;
       o = max(0,o);

     }
  }
  return 0;
}
