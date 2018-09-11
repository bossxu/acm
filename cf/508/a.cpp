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
char s[100005];
int vis[27];
int check(int k)
{
  int m = 1000000;
  int ans = 0;
  for(int i = 0;i<27;i++)
  {
    if(!vis[i]) continue;
    m = min(m,vis[i]);
  }
  for(int i = 0;i<27;i++)
  {
    if(vis[i]>=m)
      ans++;
  }
  if(ans == k)
  {
    return m;
  }
  else
  return 0;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  int k;
  while(cin>>n>>k)
  {
    clr(vis,0);
    cin>>s;
    int ans;
    for(int i = 0;i<n;i++)
    {
      vis[s[i]-'A']++;
      ans = check(k)*k;
    }
    cout<<ans<<endl;
  }
  return 0;
}
