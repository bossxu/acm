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
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
//wa 的原因 1:自己做题的一种急功近利 2: 读题不够仔细
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  int dp[46000];
  int w[11],v[11];
  while(t--)
  {
    int m,y,n;
    cin>>m>>y>>n;
    double k=1;
    for(int i=1;i<=y;i++)
    {
      k*=1.1;
    }
    clr(dp,0);
    for(int i=1;i<=n;i++)
    {
      cin>>w[i]>>v[i];
      w[i]/=1000;
    }
    for(int i=1;i<=n;i++)
        for(int j = w[i];j<=(int)(k*m/1000)+1;j++)
          dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
    int sum = 0;
    for(int i=1;i<=y;i++)
    {
      sum+=dp[(m+sum)/1000];
    }
    cout<<sum+m<<endl;
  }

  return 0;
}
