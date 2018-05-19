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
ll dp[50];
ll maxn = 0;
void dfs(ll n,ll num,int item,int pre)
{
   maxn = max(num,maxn);
   if(item>=43) return ;
   ll a = dp[item];
   int l = 1;
   while(n >= a)
   {
     if(l>pre) break;
     dfs(n/a,num*(l+1),item+1,l);
     a*=dp[item];
     l++;
   }
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  clr(dp,0);
  int flag;
  int item = 0;
  for(int i = 2;i<=200;i++)
  {
    flag = 1;
    for(int j = 2;j<i;j++)
    {
       if(i%j == 0)
       {
         flag = 0;
         break;
       }
    }
    if(flag)
    dp[item++] = i;
  }
  //cout<<item<<endl;
  int t;
  ll n;
  cin>>t;
  while(t--)
  {
    maxn = 0;
    cin>>n;
    //cout<<n<<endl;
    dfs(n,1,0,INF);
    cout<<maxn<<endl;
  }

  return 0;
}
