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
vector<ll>q;
void dfs(ll x)
{
  if(x>=10000000005)
  {
    return;
  }
  q.push_back(x);
  dfs(x*10+4);
  dfs(x*10+7);
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  ll l,r;
  dfs(0);
  sort(q.begin(),q.end());
  // for(int i = 1;i<=q.size();i++)
  // {
  //   cout<<q[i]<<" ";
  //   if(i%5 == 0) cout<<endl;
  // }
  while(cin>>l>>r)
  {
    ll ans_l = 0,ans_r = 0;
    int len = q.size();
    for(int i = 1;i<=len;i++)
    {
      //cout<<q[i]<<endl;
      if(q[i]<=l-1)
      {
        ans_l += (q[i]-q[i-1])*q[i];
      }
      else
      {
        ans_l += (l-1-q[i-1])*q[i];
        break;
      }
    }
    for(int i = 1;i<=len;i++)
    {
      if(q[i]<=r)
      {
        ans_r += (q[i]-q[i-1])*q[i];
      }
      else
      {
        ans_r += (r-q[i-1])*q[i];
        break;
      }
    }
    cout<<ans_r-ans_l<<endl;
  }


  return 0;
}
