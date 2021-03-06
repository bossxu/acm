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
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  // std::ios::sync_with_stdio(false);
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n;
    ll ans = 1;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
      int a;
      scanf("%d",&a);
      ans = ans*(a+1)%mod;
    }
    cout<<(ans-1+mod)%mod<<endl;
  }
  return 0;
}
