#include<iostream>
#include<cstdio>
#include<cstring>
<<<<<<< HEAD
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
=======
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
//套路啊套路
//遇到啥最大最小化,最小最大化的,就应该忘二分上去想.
int v[50005];
int g[3];
int s[3];
int gg[3];
int tot;
int check(int st)
{
  gg[0] = g[0],gg[1] = g[1],gg[2] = g[2];
  for(int i = 1;i<=tot;i++)
  {
    int jj = -1;
    int kk = -1;
    int need = st/v[i]+(st%v[i]>0);
>>>>>>> 23e9eb0ef042a53d02b8880db28435bf3f7acd89
    for(int j = 0;j<3;j++)
    {
      for(int k = j;k<3;k++)
      {
<<<<<<< HEAD
        int tot = 1;
        if(k == j) tot++;
        if(g[j]>=tot && g[k]>=tot && s[j]+s[k]>=lim)
        {
          if(jj == -1  ||  s[j]+s[k]<s[jj]+s[kk])
=======
        int num = 1;
        if(j == k) num = 2;
        if(gg[j]>=num && gg[k]>=num && s[j]+s[k]>=need)
        {
          if(jj = -1 || s[j]+s[k]<s[jj]+s[kk])
>>>>>>> 23e9eb0ef042a53d02b8880db28435bf3f7acd89
          {
            jj = j;
            kk = k;
          }
        }
      }
    }
<<<<<<< HEAD
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
=======
  }
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int b,n,e;
  while(cin>>g[0]>>g[1]>>g[2])
  {
    tot = (g[0]+g[1]+g[2])/2;
    cin>>s[0]>>s[1]>>s[2];
    int l,r;
    l = r = 0;
    for(int i = 1;i<=tot;i++)
    {
      cin>>v[i];
      r = max(v[i],r);
    }
    sort(v+1,v+tot+1);
    while(l<r)
    {
      int mid = (l+r)/2;
      check(mid);
    }
>>>>>>> 23e9eb0ef042a53d02b8880db28435bf3f7acd89
  }
  return 0;
}
