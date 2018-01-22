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
bool check(ll a, ll b)
{
  ll c = a/b;
  if(c*b == a)
  return true;
  return false;
}
int main()
{
  int n;
  while(cin>>n)
  {
    if(n==-1)
    break;
    ll x = 1;
    int num = 1;
    while(x%n != 0)
    {
      x = x*10+1;
      x %= n;
      num++;
    }
    cout<<num<<endl;
  }
  return 0;
}
