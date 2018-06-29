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
int shu[100005];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n;
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    int maxn,minn,totx,toti;
    int num = 1;
    int ans = 1;
    maxn = minn = shu[1];
    totx = toti = 1;
    for(int i = 2;i<=n;i++)
    {
      if(shu[i]>maxn)
      {
        if(shu[i] - maxn >= 2)
        {
          num = 1;
          toti = totx = i;
          maxn = minn = shu[i];
          continue;
        }
        if(shu[i]-minn >=2)
        {
          minn = shu[totx];
          maxn = shu[i];
          num = i-toti;
          toti = totx;
          totx = i;
        }

        else
        {
          maxn = shu[i];
          totx = i;
          num++;
        }
      }
      else if(shu[i]<minn)
      {
        if(minn - shu[i]>=2)
        {
          num = 1;
          toti = totx = i;
          maxn = minn = shu[i];
          continue;
        }
        if(maxn-shu[i] >=2)
        {
          maxn = shu[toti];
          minn = shu[i];
          num = i-totx;
          totx = toti;
          toti = i;
        }
        else
        {
          minn = shu[i];
          toti = i;
          num++;
        }
      }
      else
      {
        num++;
        if(shu[i] == minn)
        {
          toti = i;
        }
        if(shu[i] == maxn)
        {
          totx = i;
        }
      }
      //cout<<i<<" "<<toti<<" "<<totx<<" "<<num<<endl;
      ans = max(ans,num);
    }
    cout<<ans<<endl;
  }

  return 0;
}
