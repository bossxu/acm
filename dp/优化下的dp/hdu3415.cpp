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
const int N = 1e5+5;
vector<int>q;
ll sum[N*2];
ll que[N*2];
ll dp[N*2];
int n,k;
int ans,st,len;
void slove()
{
  for(int i = 1;i<=n;i++)
  {
    q.pb(q[i]);
  }
  sum[0] = 0;
  for(int i = 1;i<=2*n;i++)
  {
    sum[i] = sum[i-1] +q[i];
  }
  int head = 1,tail = 1;
  ans = sum[1],st = 1,len = 1;
  for(int i = 1;i<=2*n;i++)
  {
    while(head!=tail && (i-que[head]>k || sum[que[head]]<=sum[que[head+1]])) head++;
    dp[i] = sum[i] - sum[que[head]];
    if(dp[i] >= ans)
    {
      if(ans == dp[i])
      {
        if(i-que[head] < len-1)
      {
        st = que[head]+1;
        len = i-que[head];
      }
      }
      else
      {
        st = que[head]+1;
        len = i-que[head];
      }
      ans = dp[i];
    }
    while(head!=tail && sum[que[tail]] <= sum[i] ) tail--;
    que[++tail] = i;
  }
}
int main()
{
  ios_close;
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    q.clear();
    q.pb(-1);
    int a;
    for(int i = 1;i<=n;i++)
    {
      cin>>a;
      q.pb(a);
    }
    slove();
    cout<<ans<<" "<<st<<" "<<len<<endl;
  }
  return 0;
}
