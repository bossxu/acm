#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll long long
const int maxn = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
int r[3];
int s[3];
int v[50005];
int num;
//二分贪心check
//那个时候没想到
bool check(int aim)
{
  int g[3];
  for(int i = 0;i<3;i++)
  {
    g[i] = r[i];
  }
  for(int i = 1;i<=num;i++)
  {
    int lim = aim/v[i] + (aim%v[i] > 0);
    int jj = -1,kk = -1;
    for(int j = 0;j<3;j++)
    {
      for(int k = j;k<3;k++)
      {
        int tot = 1;
        if(k == j) tot++;
        if(g[j]>=tot && g[k]>=tot && s[j]+s[k]>=lim)
        {
          if(jj == -1  ||  s[j]+s[k]<s[jj]+s[kk])
          {
            jj = j;
            kk = k;
          }
        }
      }
    }
    if(jj == -1) return 0;
    g[jj]--;
    g[kk]--;
  }
  return 1;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while(cin>>r[0]>>r[1]>>r[2])
  {
    num = r[0]+r[1]+r[2];
    num/=2;
    for(int i = 0;i<3;i++)
    {
      cin>>s[i];
    }
    for(int i = 1;i<=num;i++)
    {
      cin>>v[i];
    }
    int l,r;
    l = 0;
    r = 100000*(s[2]+s[2]);
    int ans;
    while(l<=r)
    {
      ll mid = (l+r)>>1;
      //cout<<mid<<endl;
      if(check(mid))
      {
        ans = mid;
        l = mid+1;
      }
      else
      {
        r = mid-1;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
