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
#define ll unsigned long long
#define clr(a,x) memset(a,x,sizeof(a))
const ll maxn = 3000000000000000000;
struct Node
{
  int two,three;
  ll index;
}node[105];
int cmp(Node a , Node b)
{
  if(b.three == a.three)
  {
    return a.two<b.two;
  }
  return a.three>b.three;
}
ll dp2[64],dp3[64];
void init()
{
  ll n = 1;
  int item = 0;
  while(n<=maxn)
  {
    dp2[item++] = n;
    n*=2;
  }
  n = 1;
  item = 0;
  while(n<=maxn)
  {
    dp3[item++] = n;
    n*=3;
  }
}
int main()
{
  int n;
  init();
  while(cin>>n)
  {
    ll a;
    for(int i = 1;i<=n;i++)
    {
      cin>>a;
      node[i].two = node[i].three = 0;
      while(a%2 == 0)
      {
        a/=2;
        node[i].two++;
      }
      while(a%3 == 0)
      {
        a/=3;
        node[i].three++;
      }
      node[i].index = a;
    }
    sort(node+1,node+n+1,cmp);
    a = node[1].index*dp2[node[1].two]*dp3[node[1].three];
    cout<<a;
    for(int i = 2;i<=n;i++)
    {
      a = node[i].index*dp2[node[i].two]*dp3[node[i].three];
      cout<<" "<<a;
    }
    cout<<endl;
  }
  return 0;
}
