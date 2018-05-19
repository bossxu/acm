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
  std::ios::sync_with_stdio(false);
  int shu[1005];
  int n;
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    sort(shu+1,shu+n+1);
    if(n%2 == 0)
    {
      cout<<shu[n/2]<<endl;
    }
    else
    {
      cout<<shu[n/2+1]<<endl;
    }
  }

  return 0;
}
