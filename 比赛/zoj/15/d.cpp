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
char s[1005];
int num[1005];
int dp[1005];
void swap(int i,int j)
{
  char o;
  int k;
  k = num[i],num[i] = num[j],num[j] =k;
  o = s[i],s[i] = s[j] , s[j] = o;
}
int n;
ll ans;
int dfs(int l,ll flag)
{
  ans = max(flag,ans);
  if(~dp[l]) {return dp[l];}
  for(int i = l;i<n;i++)
  {
    if(s[i] == '(' && s[i+1] == ')')
    {
      int k = i+1;
      while(k>=l+1 && s[k-1]=='(')
      {
        swap(k-1,k);
        dfs(k,num[k-1]*num[k]+flag);
        k--;
      }
    }
  }

}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   while(t--)
   {
     cin>>n;
     scanf("%s",s);
     int ans = 0;
     clr(dp,-1);
     for(int i = 0;i<n;i++)
     {
       scanf("%d",&num[i]);
     }
     for(int i = 0;i<n-1;i++)
     {
       if(s[i] == '(' && s[i+1] == ')')
       {
         int k = i+1;
         while(k>=0 && s[k-1]=='(')
         {
           swap(k-1,k);
           dfs(k,num[k-1]*num[k]);
           k--;
         }
       }
     }
     cout<<ans<<endl;
   }

  return 0;
}
