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
int sg[1006];
void find(int st)
{
  int vis[1005];
  clr(vis,0);
  for(int i = 0;i<st;i++)
  {
    vis[sg[i]] = 1;
  }
  for(int i = 1;i<st;i++)
  {
    vis[sg[i]^sg[st-i]] = 1;
  }
  for(int i = 0;i<=1000;i++)
  {
    if(!vis[i])
    {
      sg[st] = i;
      return;
    }
  }
}
int main()
{
   //freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  sg[0] = 0;
  for(int i = 1;i<=1000;i++)
  {
    sg[i] = -1;
  }
  for(int i = 1;i<=100;i++)
  {
    find(i);
  }
  for(int i = 1;i<=100;i++)
  {
    cout<<i<<" ---- ";
    cout<<sg[i]<<endl;
  }
  return 0;
}
