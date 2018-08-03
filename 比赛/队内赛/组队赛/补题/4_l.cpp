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
#include<map>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
//这题是赛时被卡了精度
//忘记了我们可用log这些函数
map<string,double>op;
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  // std::ios::sync_with_stdio(false);
  // cin.tie(0);
  int n;
  while(cin>>n)
  {
    string s1,s2;
    double bi;
    op.clear();
    op["pink"] = 0.0;
    for(int i = 1;i<=n;i++)
    {
      cin>>s1>>s2>>bi;
      if(op.find(s2)==op.end())
        continue;
      if(op.find(s1)==op.end())
      {
        op[s1] = op[s2]+log(bi);
      }
      else
      {
        op[s1] = max(op[s1],op[s2]+log(bi));
      }
    }
    double ans = 0;
    if(op.find("blue")!=op.end())
    {
      ans = min((double)10.0,exp(op["blue"]));
    }
    printf("%.7lf\n",ans);
  }
  return 0;
}
