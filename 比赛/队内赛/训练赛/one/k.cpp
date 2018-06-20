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
char s[100];
ll dp[15];
void init()
{
  dp[0] = 1;
  for(int i = 1;i<=14;i++)
  {
    dp[i] = dp[i-1]*i;
  }
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  //std::ios::sync_with_stdio(false);
   int t;
   scanf("%d",&t);
   int n;
   init();
   while(t--)
   {
     scanf("%d",&n);
     scanf("%s",s);
     int vis[27];
     clr(vis,0);
     for(int i = 1;i<=n;i++)
     {
       vis[s[i-1]-'a']++;
     }
     int num = 0;
     for(int i = 0;i<26;i++)
     {
       if(vis[i]%2) num++;
     }
     if(num>=2)
     {
       cout<<0<<endl;
       continue;
     }
     ll ans = dp[n/2];
     for(int i = 0;i<26;i++)
     {
       ans/=dp[vis[i]/2];
     }
     cout<<ans<<endl;
   }

  return 0;
}
