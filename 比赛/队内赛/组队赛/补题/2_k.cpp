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
    for(int j = 0;j<3;j++)
    {
      for(int k = j;k<3;k++)
      {
        int num = 1;
        if(j == k) num = 2;
        if(gg[j]>=num && gg[k]>=num && s[j]+s[k]>=need)
        {
          if(jj = -1 || s[j]+s[k]<s[jj]+s[kk])
          {
            jj = j;
            kk = k;
          }
        }
      }
    }
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
  }
  return 0;
}
