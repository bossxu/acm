#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll long long
const int maxn = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
double shu[5005];
int main()
{
  int n;
  int k;
  while(cin>>n>>k)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
     double ans = 0;
     double sum = 0;
    for(int i = 1;i<=k;i++)
    {
      sum+=shu[i];
    }
    for(int i = 0;k+i<=n;i++)
    {
      //cout<<i<<"----" <<endl;
      double it = sum;
      for(int j = 1;j<=i;j++)
      {
        it+=shu[k+j];
      }
       double maxn = it;
       double op = it;
      for(int j = k+i+1;j<=n;j++)
      {
        //cout<<shu[j]<<" "<<shu[j-k-i]<<endl;
        op += shu[j] - shu[j-k-i];
        maxn = max(maxn,op);
      }
      //cout<<maxn<<endl;
      ans = max(ans,maxn/(double)(k+i));
    }
    printf("%.9lf\n",ans);
  }
  return 0;
}
