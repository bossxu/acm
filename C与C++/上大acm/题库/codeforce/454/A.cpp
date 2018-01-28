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
  int a,b,c,d;
  while(cin>>a>>b>>c>>d)
  {
    if(d>c*2 || c>2*d || b <= d)
    {
      cout<<"-1"<<endl;
    }
    else
    {
      cout<<a*2<<endl<<b*2<<endl<<max(c,d)<<endl;
    }
  }
  return 0;
}
