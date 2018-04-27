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
struct node
{
  int x,y;
}nod[105];
int pra[105];
int vis[1005];
int getroot(int t)
{
  if(pra[t]!=t) return getroot(pra[t]);
  return t;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n;
  while(cin>>n)
  {
    int a,b;
    clr(vis,0);
    for(int i = 1;i<=n;i++)
    {
      pra[i] = i;
      cin>>nod[i].x>>nod[i].y;
    }
    for(int i = 1;i<=n;i++)
    {
      for(int j = i+1;j<=n;j++)
      {
        if(nod[i].x == nod[j].x || nod[i].y == nod[j].y)
        {
          int k1 = getroot(i),k2 = getroot(j);
          pra[k2] = k1;
        }
      }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
      int k = getroot(i);
      if(!vis[k])
      {
        ans++;
      }
      vis[k]=1;
    }
    cout<<ans-1<<endl;

  }
  return 0;
}
