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
ll shu[1005];
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    ll x;
    int n;
    cin>>x>>n;
    int xun = 2*(n-1);
    if(n == 1)
    {
      cout<<x<<endl;
      continue;
    }
    clr(shu,0);
    //cout<<xun<<endl;
    for(int i = 1;i<=n;i++)
    {
      shu[i] = x/xun;
    }
    for(int i = 2;i<=n-1;i++)
    {
      shu[i] += x/xun;
    }
    ll liu = x - xun*shu[1];
    for(int i = 1;i<=n && liu;i++)
    {
      liu--;
      shu[i]++;
    }
    for(int i = n-1;i>=1 && liu;i--)
    {
      liu--;
      shu[i]++;
    }
    for(int i = 1;i<=n;i++)
    {
      cout<<shu[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
