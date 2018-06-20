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
int shu[10005][27];
char s[10005];
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  //std::ios::sync_with_stdio(false);
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n,q;
    scanf("%d%d",&n,&q);
    clr(shu,0);
    scanf("%s",s);
    for(int i = 1;i<=n;i++)
    {
      shu[i][s[i-1]-'a'] = 1;
      for(int j = 0;j<=25;j++)
      {
        shu[i][j] += shu[i-1][j];
      }
    }
    for(int i = 1;i<=q;i++)
    {
      char ok;
      int l,r;
      scanf("%d %d %c",&l,&r,&ok);
      int ind = ok-'a';
      int l1 = (l/n)*shu[n][ind];
      if(l%n == 0)
      {
        l1-=shu[n][ind]-shu[n-1][ind];
      }
      else
      l1+=shu[l%n-1][ind];
      int l2 = (r/n)*shu[n][ind]+shu[r%n][ind];
      printf("%d\n",l2-l1);
    }
  }
  return 0;
}
