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
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
const int maxn = 1005;
// 扩展中国剩余定理
int k;
ll chu[maxn],yu[maxn];// 除数 余数
ll yu1,yu2,chu1,chu2;
ll item;
bool flag;
ll gcd(ll a,ll b)
{
  if(!b) return a;
  else return gcd(b,a%b);
}
void exgcd(ll a,ll b,ll &x,ll &y)
{
  if(!b) x = 1,y = 0;
  else exgcd(b,a%b,y,x) , y-=a/b*x;
}
ll inv(ll a,ll b)
{
  ll x = 0,y =0;
  exgcd(a,b,x,y);
  x = (x%b+b)%b;
  if(!x) x+=b;
  return x;
}
void slove()
{
  flag = 1;
  for(int i = 2;i<=k;i++)    //k组数
  {
    yu1 = yu[i-1],yu2 = yu[i];
    chu1 = chu[i-1],chu2 = chu[i];
    item = gcd(chu1,chu2);
    if((yu1 - yu2)%item!=0)
    {flag = 0;break;}
    chu[i] = chu1*chu2/item;
    yu[i] = inv(chu1/item,chu2/item) * ((yu2 - yu1)/item)%(chu2/item)*chu1+yu1;
    yu[i] = (yu[i]%chu[i]+chu[i])%chu[i];
  }
  if(!flag) cout<<"-1"<<endl;
  else
  cout<<yu[k]<<endl;
}

int main()
{
  int n;
  while(cin>>n)
  {
    k = n;
    for(int i = 1;i<=k;i++)
    {
      cin>>chu[i]>>yu[i];
    }
    slove();
  }
  return 0;
}
