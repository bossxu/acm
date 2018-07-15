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
const int MAXN = 100005;
bool check[MAXN+10];
int prime[MAXN+10];
int mu[MAXN+10];
int gcd(int a,int b)
{
  return b == 0?a:gcd(b,a%b);
}
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
  std::ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  int n,m;
  Moblus();
  while(cin>>n>>m)
  {
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    {
      ans+=(ll)mu[i]*(n/i)*(n/i);
    }
    ans  = (ans-1)/2;
    if(ans>=m && m>=n-1)
    {
      cout<<"Possible"<<endl;
      int tot = 0;
      for(int i = 1;i<=n;i++)
      {
        for(int j = i+1;j<=n;j++)
        {
          if(gcd(i,j) == 1)
          {
            cout<<i<<" "<<j<<endl;
            tot++;
          }
          if(tot==m) break;
        }
        if(tot == m) break;
      }
    }
    else
    {
      cout<<"Impossible"<<endl;
    }
  }
  return 0;
}
