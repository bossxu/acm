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
//莫比乌斯反演题
const int MAXN = 100005;
bool check[MAXN+10];
int prime[MAXN+10];
int mu[MAXN+10];
void moblus()
{
  clr(check,0);
  mu[1] = 1;
  int tot = 0;
  for(int i = 2;i<=MAXN;i++)
  {
    if(!check[i])
    {
        prime[tot++] = i;
        mu[i] = -1;
    }
    for(int j = 0;j<tot;j++)
    {
      if(i*prime[j]>MAXN) break;
      check[i*prime[j]] = true;
      if(i%prime[j] == 0)
      {
        mu[i*prime[j]] = 0;break;
      }
      else
      {
        mu[i*prime[j]] = -mu[i];
      }
    }
  }
}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n;
  while(cin>>n)
  {
    int l1,l2,r1,r2;
    int k;
    cin>>l1>>l2>>r1>>r2>>k;
    if(k == 0)
    {
        cout<<0<<endl;
        continue;
    }
    l1/=k,l2/=k,r1/=k,r2/=k;

  }
  return 0;
}
