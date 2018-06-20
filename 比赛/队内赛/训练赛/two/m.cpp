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
ll shu[20];
ll ans,n;
int m;
int item;
int vis[20];
ll gcd(ll a,ll b)
{
  return b == 0?a:gcd(b,a%b);
}
void dfs(ll pre,int i,int length)
{
  if(i>item) return ;
  if(pre > n) return;
  vis[length+1]++;
  int flag = length%2?-1:1;
  ans += flag*n/(pre/gcd(pre,shu[i])*shu[i]);
  //cout<<ans<<endl;
  dfs(pre,i+1,length);
  dfs(pre*shu[i],i+1,length+1);
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  while(cin>>n>>m)
  {
    ans = 0;
    clr(vis,0);
    item = m;
    int i = 1;
    while(m--)
    {
      cin>>shu[i];
      if(shu[i]!=1 && shu[i]<n && shu[i]!=0) i++;
      else item--;
    }
    dfs(1,1,0);
    //for(int i = 1;i<=item;i++) cout<<vis[i]<<endl;
    cout<<n-ans<<endl;
  }
  return 0;
}
