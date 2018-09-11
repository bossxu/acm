#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define c_fuck(x) cout<<"Case "<<x<<":"
#define debug cout<<"is there bug?"<<endl
const int mod = 1e9+7;
const double eps = 1e-6;
ll p[100005];
ll d[100005];
ll f[100005];
ll vector<int>shu;
ll dp[3][100005];
void init(int n)
{
  clr(dp,0);
  for(int i = 1;i<=n;i++)
  {
    cin>>p[i];
  }
  for(int i = 1;i<=n;i++)
  {
    cin>>d[i];
  }
  for(int i = 1;i<=n;i++)
  {
    cin>>f[i];
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin>>n)
  {
    init();

  }
  return 0;
}
