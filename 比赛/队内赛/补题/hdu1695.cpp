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
#define clr(a,x) memset(a,x,sizeof(a))
//莫比乌斯反演简单题
const int MAXN = 100005;
bool check[MAXN+10];
int prime[MAXN+10];
int mu[MAXN+10];
void Moblus()
{
    clr(check,0);
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i <= MAXN; i++)
    {
        if( !check[i] )
        {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; j++)
        {
            if(i * prime[j] > MAXN) break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}

int main()
{
  //std::ios::sync_with_stdio(false);
  int t;
  cin>>t;
  int tot = 1;
  Moblus();
  while(t--)
  {
    int a,l,b,r;
    int k;
    cin>>a>>l>>b>>r>>k;
    cout<<"Case "<<tot++<<": ";
    if(k == 0)
    {
      cout<<0<<endl;
      continue;
    }
    l/=k;r/=k;
    ll ans = 0;
    for(int i = 1;i<=min(l,r);i++)
    {
      ans+=(ll)mu[i]*(l/i)*(r/i);
    }
    ll chong = 0;
    for(int i = 1;i<=min(l,r);i++)
    {
      chong+=(ll)mu[i]*(min(l,r)/i)*(min(l,r)/i);
    }
    cout<<ans-chong/2<<endl;
  }
  return 0;
}
