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
//比较基础的一道数学题
//目的在于求
int main()
{
  // freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  // std::ios::sync_with_stdio(false);
  // cin.tie(0);
  int n,p;
  while(cin>>n>>p)
  {
    int x = n/(p-1);
    double init = 1.0;
    init = x*p*1.0/(n+1);
    for(int i = 2;i<=x;i++)
    {
      init *= (n-p+i)*1.0/(n+i);
    }
    printf("%.7lf\n",init);
  }
  return 0;
}
