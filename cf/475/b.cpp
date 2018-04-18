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
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int shu[1005];
  int n,a,b,c,t;
  while(cin>>n>>a>>b>>c>>t)
  {
    for(int i = 1;i<=n;i++)
      cin>>shu[i];
    sort(shu+1,shu+n+1);
    if(b>=c)
    {
      cout<<a*n<<endl;
      continue;
    }
    else
    {
      int ans = 0;
      for(int i = 1;i<=n;i++)
      {
        ans+=t-shu[i];
      }
      cout<<a*n+ans*(c-b)<<endl;
    }

  }
  return 0;
}
