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
double map[1005][1005];
double sum[1005];
//我感觉是很难的一道题
//还有我的数学真的存在问题,我的推到更偏向于找规律,而不是自己去推
//这个要改
//以推算为主
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  //std::ios::sync_with_stdio(false);
  int n,m;
  while(cin>>n>>m)
  {
    clr(sum,0);
    clr(map,0);
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        scanf("%lf",&map[i][j]);
        sum[i]+=map[i][j];
      }
    }
      double ans = 0;
      for(int i = 1;i<=m;i++)
      {
        double s1 = 0,s2 = 0;
        for(int j = 1;j<=n;j++)
        {
          double p = map[j][i]/sum[j];
          s1+=p;
          s2+=p*p;
        }
        ans+=s1+s1*s1-s2;
      }
      printf("%.2lf\n",ans);
    }
  return 0;
}
