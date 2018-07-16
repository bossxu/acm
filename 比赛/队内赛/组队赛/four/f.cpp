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
int shu[20];
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while(cin>>n)
  {
    int sum = 0;
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
      sum+=shu[i];
    }
    sort(shu+1,shu+n+1);
    int op = 0;
    for(int i = n;i>=1;i-=2)
    {
      op+=shu[i];
    }
    cout<<op<<" "<<sum-op<<endl;
  }
  return 0;
}
