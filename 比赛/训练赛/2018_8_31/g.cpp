#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;

ll op[405][405];
ll csl[405][405];
ll mwh[405][405];
int n;
ll ans;
void init()
{
  clr(csl,0);
  clr(mwh,0);
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=n;j++)
    {
      csl[i][j] += op[i][j]+csl[i-1][j-1];
    }
  }
  for(int i = 1;i<=n;i++)
  {
    for(int j = n;j>=1;j--)
    {
      mwh[i][j] += op[i][j]+mwh[i-1][j+1];
    }
  }
  // cout<<endl;
  // for(int i = 1;i<=n;i++)
  // {
  //   for(int j = 1;j<=n;j++)
  //   {
  //     cout<<csl[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  // cout<<endl;
  // for(int i = 1;i<=n;i++)
  // {
  //   for(int j = 1;j<=n;j++)
  //   {
  //     cout<<mwh[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  // cout<<endl;
}
void slove()
{
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=n;j++)
    {
      for(int k = 1;k<min(i,j);k++)
      {
        ans = max(csl[i][j] - csl[i-k-1][j-k-1] - (mwh[i][j-k]-mwh[i-k-1][j+1]),ans);
        //cout<<i<<" "<<j<<" "<<k<<" "<<csl[i][j] - csl[i-k-1][j-k-1]<<" "<<mwh[i][j-k]-mwh[i-k-1][j+1]<<endl;
      }
    }
  }
}
int main()
{
  ios_close;
  int t;
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  cin>>t;
  while(t--)
  {
    cin>>n;
    clr(op,0);
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=n;j++)
      {
        cin>>op[i][j];
      }
    }
    init();
    ans = 0;
    slove();
    cout<<ans<<endl;
  }
  return 0;
}
