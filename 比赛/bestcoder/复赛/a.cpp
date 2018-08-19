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
vector<int>son[100005];
ll a[100005];
ll maxn,minn;
ll nextmax = 0,nextmin = 0;
void dfs(int st)
{
  ll b1 = 0,b2 = 0;
  ll s1 = 0,s2 = 0;
  int len = son[st].size();
  for(int i = 0;i<len;i++)
  {
    ll k = max(a[son[st][i]],1LL*0);
    ll l = min(a[son[st][i]],1LL*0);
    if(k > b2)
    {
      if(k > b1)
      {
        b2 = b1;
        b1 = k;
      }
      else
      b2 = k;
    }
    if(l < s2)
    {
      if(l<s1)
      {
        s2 = s1;
        s1 = l;
      }
      else
      {
        s2 = l;
      }
    }
    dfs(son[st][i]);
  }
  maxn += b1;
  nextmax = max(b2,nextmax);
  minn += s1;
  nextmin = min(s2,nextmin);
  //cout<<st<<" "<<s1<<" "<<s2<<endl;
}
int main()
{
  ios_close;
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  int n;
  int t;
  cin>>t;
  while(t--)
  {
    clr(a,0);
    cin>>n;
    for(int i = 1;i<=n;i++) son[i].clear();
    for(int i = 2;i<=n;i++)
    {
      int pre;
      cin>>pre;
      son[pre].pb(i);
    }
    for(int i = 1;i<=n;i++)
    {
      cin>>a[i];
    }
    maxn = max(a[1],1LL*0);
    minn = min(a[1],1LL*0);
    nextmax = 0,nextmin = 0;
    dfs(1);
    cout<<maxn+nextmax<<" "<<minn+nextmin<<endl;
  }

  return 0;
}
