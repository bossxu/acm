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
#define cle(a,n) for(int i=1;i<=n;i++) a[i].clear();
const double eps = 1e-6;
//多自己推
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n,k;
  int tot = 0;
  while(cin>>n>>k)
  {
    cout<<"Case "<<(++tot)<<": ";
    if(k == 1)
    {
      if(n%2 == 1)
      {
        cout<<"Bob"<<endl;
      }
      else
        cout<<"Alice 1"<<endl;
    }
    else
    {
      cout<<"Alice ";
      if(n-2*k == 1) cout<<k<<endl;
      else cout<<1<<endl;
    }
  }
  return 0;
}
