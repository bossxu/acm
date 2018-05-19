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
struct Node
{
  ll l,r;
  ll cha;
}node[5];
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--)
  {
    for(int i = 1;i<=4;i++)
    {
      cin>>node[i].l>>node[i].r;
      node[i].cha = node[i].r - node[i].l+1;
    }
    ll sum = 1;
    for(int i = 1;i<=4;i++) sum = sum*node[i].cha%mod;
    ll a = 0;
    for(int i = 1;i<=4;i++)
    {
      int j = (i+1)%4;
      if(j == 0) j = 4;
      ll  l = max(node[i].l,node[j].l);
      ll  r = min(node[i].r,node[j].r);
      ll cha = r-l+1;
      if(cha<0) cha = 0;
      for(int k = 1;k<=4;k++)
      {
        if(k!=i && k!=j)
        {
           cha = cha*node[k].cha%mod;
        }
      }
      a = (cha+a)%mod;
    }
    ll b = 0;
    for(int i = 1;i<=4;i++)
    {
       int j = (i+1)%4; if(j == 0) j =4;
       int k = (i+2)%4; if(k == 0) k =4;
          ll l = max(node[i].l,max(node[j].l,node[k].l));
          ll r = min(node[i].r,max(node[j].r,node[k].r));
          ll cha = r-l+1;
          if(cha<0) cha = 0;
          for(int p = 1;p<=4;p++)
          {
            if(p!=i && p!=j && p!=k)
            {
              cha = cha*node[p].cha%mod;
            }
          }
          b = (cha+b)%mod;
    }
    //cout<<b<<endl;
    ll  l = max(node[1].l,node[2].l);
    ll  r = min(node[1].r,node[2].r);
    ll  l1 = max(node[3].l,node[4].l);
    ll  r1 = min(node[3].r,node[4].r);
    ll cha = r-l+1;
    ll cha1 = r1-l1+1;
    if(cha<0) cha = 0;
    if(cha1<0) cha1= 0;
    b = (b+cha*cha1%mod)%mod;
    //cout<<b<<endl;
     l = max(node[2].l,node[3].l);
     r = min(node[2].r,node[3].r);
     l1 = max(node[1].l,node[4].l);
     r1 = min(node[1].r,node[4].r);
     cha = r-l+1;
     cha1 = r1-l1+1;
    if(cha<0) cha = 0;
    if(cha1<0) cha1= 0;
    //cout<<cha<<" "<<cha1<<endl;
    b = (b+cha*cha1%mod)%mod;
  //  cout<<b<<endl;
     l = max(node[1].l,max(node[2].l,max(node[4].l,node[3].l)));
     r = min(node[1].r,max(node[2].r,max(node[3].r,node[4].r)));
     cha = r-l+1;

    if(cha<0) cha=0;
    cha = cha*3%mod;
    //cout<<a<<" "<<b<<" "<<cha<<endl;
    sum = (sum-a+b-cha)%mod;
    if(sum<0) sum+=mod;

    cout<<sum<<endl;
  }
  return 0;
}
