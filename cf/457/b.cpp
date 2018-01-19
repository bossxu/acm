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
int shu[70];
int dfs(ll a)
{
  int i = 0;
  int p = 0;
  //int dp[70];
  while(a)
  {
    if(a%2)
    {
      shu[i++] = p;
    }
    a/=2;
    p++;
  }
  return i;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ll n;
  int k;
  while(cin>>n>>k)
  {
    priority_queue<int>ans;
    int l = dfs(n);
    for(int i = 0;i<l;i++)
    {
      ans.push(shu[i]);
    }
    if(l>k)
    {
      cout<<"No"<<endl;
      continue;
    }
    while(ans.size()<k)
    {
      int o = ans.top();
      ans.pop();
      ans.push(o-1);
      ans.push(o-1);
    }
    cout<<"Yes"<<endl;    
    while(ans.size()!=1)
    {
      cout<<ans.top();
      cout<<" ";
      ans.pop();
    }
    cout<<ans.top()<<endl;
  }
  return 0;
}
