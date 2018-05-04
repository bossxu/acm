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
int shu[400005];
int a[100005];
int b[100005];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
      scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&b[i]);
      b[i] = a[i]-b[i];
    }
    clr(shu,0);
    int maxn = 1;
    for(int i = 1;i<=n;i++)
    {
      b[i]+=200000;
      shu[b[i]]++;
      maxn = max(maxn,shu[b[i]]);
    }
    cout<<maxn<<endl;
  }

  return 0;
}
