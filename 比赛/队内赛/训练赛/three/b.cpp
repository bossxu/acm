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
const double eps=1e-8;//解析几何中有时并不能保证等于0，在误差范围就行
struct CPoint//点的存法
{
    long double x,y;
}point[103];


int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--)
  {
    for(int i =0;i<4;i++)
    {
      cin>>point[i].x>>point[i].y;
    }

  }
  return 0;
}
