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
int shu[1000005];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int t;
  cin>>t;
  int n;
  int maxn = 0;
  while(t--)
  {
    cin>>n;
    int a;
    maxn = 0;
    for(int i = 1;i<=n;i++)
    {
      cin>>a;
      shu[a] = i;
    }
    int  flag = 0;
    for(int i = n;i>0;i-=2)
    {
      if(shu[i]<shu[i-1])
      {
        flag = 1;
        cout<<i<<endl;
        break;
      }
    }

  }
  return 0;
}
