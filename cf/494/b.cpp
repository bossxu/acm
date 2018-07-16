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
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int a,b,n;
  while(cin>>a>>b>>n)
  {
    if(a == n/2)
    {
      cout<<1;
      b--;
    }
    for(int i = 1;i<=n-1;i++)
    {
      if(i%2)
      {
        cout<<0;
        a--;
      }
      else
      {
        cout<<1;
        b--;
      }
    }
    if(n%2 == 0)
    {
      for(int i = 1;i<=b;i++)
      {
        cout<<1;
      }
      for(int i = 1;i<=a;i++)
      {
        cout<<0;
      }
    }
    else
    {
      for(int i = 1;i<=a;i++)
      {
        cout<<0;
      }
      for(int i = 1;i<=b;i++)
      {
        cout<<1;
      }
    }
    cout<<endl;
  }
  return 0;
}
