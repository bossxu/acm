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
ll shu[1004];
const int N=1e6+5;
bool mark[N];
int prim[N];
int cnt;
void initial()
{
    cnt=0;
    for (int i=2 ; i<N ; ++i)
    {
        if (!mark[i])
            prim[cnt++]=i;
        for (int j=0 ; j<cnt && i*prim[j]<N ; ++j)
        {
            mark[i*prim[j]]=1;
            if (!(i%prim[j]))
                break;
        }
    }
}
ll sum[N];
ll dp[2][1005];
int main()
{
  int n,b;
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  initial();
  while(cin>>b>>n)
  {
    clr(dp,0);
    clr(sum,0);
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    ll yu = 0;
    for(int i = 1;i<=n;i++)
    {
      for(int j = 0;j<cnt;j++)
      {
        int num = 0;
        while(shu[i]%prim[j] == 0) num++,shu[i]/=prim[j];
        sum[j] += num;
      }
      if(shu[i]!=1) yu ++;
    }
    int now = 0;
    if(b == 1)
    {
      cout<<1<<endl;
      continue;
    }
  //  dp[now][1] = 1;
    for(int i = 0;i<cnt;i++)
    {
        if(sum[i] == 0) continue;
        //cout<<prim[i]<<" "<<sum[i]<<endl;
        int next = now^1;
        clr(dp[next],0);
        for(int k = 2;k<=min(sum[i]+1,1LL*b);k++) (dp[next][k] += 1)%=mod;
        for(int j = 1;j<=b;j++)
        {
          for(int k = 1;k<=sum[i]+1 && j*k<=b;k++)
          {
            (dp[next][j*k] += dp[now][j])%=mod;
          }
        }
        now = next;
    }
    //cout<<yu<<endl;
    for(int i = 1;i<=yu;i++)
    {
      int next = now^1;
      clr(dp[next],0);
      for(int j = 1;j<=b;j++)
      {
        (dp[next][j] += dp[now][j])%=mod;
        (dp[next][2] += 1)%=mod;
        (dp[next][j*2] += dp[now][j])%=mod;
      }
      now = next;
    }
    cout<<dp[now][b]<<endl;
  }
  return 0;
}
