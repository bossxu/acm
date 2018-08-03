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
//const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
ll shu[10000005];
ll maxra[10000005];
ll cou[10000006];
ll nextmax[10000005];
ll st[10000005];
ll n,m,k,p,q,r,mod;
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n>>m>>k>>p>>q>>r>>mod;
    for(int i = 1;i<=k;i++)
    {
      cin>>shu[i];
    }
    for(int i = k+1;i<=n;i++)
    {
      shu[i] = (p*shu[i-1]+q*i+r)%mod;
    }
    int maxn = 0, ra = 0;
    int num = 0;
    for(int i = 1;i<=m;i++)
    {
      if(shu[i]>maxn)
      {
        maxn = shu[i];
        ra++;
      }
    }
    maxra[1] = maxn;
    cou[1] = ra;
    int tot  = -1;
    st[++tot] = n;
    for(int i = n-1;i>=1;i--)
    {
      if(shu[i]>shu[st[tot]])
      {
        while(tot>=0 && shu[i]>shu[st[tot]])
        {
          tot--;
        }
        if(tot == -1)
        {
          nextmax[i] = -1;
        }
        else
        {
          nextmax[i] = st[tot];
        }
        st[++tot] = i;
      }
      else
      {
        nextmax[i] = st[tot];
        st[++tot] = i;
      }
    }
  //  for(int i = 1;i<=n;i++)
  //  {
  //    cout<<nextmax[i]<<" ";
  //  }
  //  cout<<endl;

    for(int i = m+1;i<=n;i++)
    {
      if(shu[i-m+1]>shu[i-m])
      {
        ra--;
      }
      if(shu[i-m+1]<shu[i-m])
      {
        if(nextmax[i-m] == -1 || nextmax[i-m]-i+m>=m)
        {
          ra = 0,maxn = 0;
          for(int j = i-m+1;j<=i;j++)
          {
            if(shu[j]>maxn)
            {
              maxn = shu[j],ra++;
            }
          }
        }
        else
        {
          ra--;
          int ok = 0;
          for(int j = i-m+1;j<nextmax[i-m];j++)
          {
            if(shu[j]>ok)
            {
              ra++;
              ok = shu[j];
            }
          }
        }
      }
      if(shu[i]>maxn)
      {
        maxn = shu[i];
        ra++;
      }
      maxra[i-m+1] = maxn;
      cou[i-m+1] = ra;
    }

    ll A = 0,B = 0;
    for(int i = 1;i<=n-m+1;i++)
    {
      //cout<<i<<" "<<maxra[i]<<" "<<cou[i]<<endl;
      A = A+(i^maxra[i]);
      B = B+(i^cou[i]);
    }
    cout<<A<<" "<<B<<endl;
  }
  return 0;
}
