#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-6;
int len,k;
ll maxn,minn;
void dfs_b(string s,int cao,int wei)
{
  ll ans = 0;
  //cout<<s<<" "<<cao<<" "<<wei<<" "<<len<<" "<<k<<endl;
  for(int i = 0;i<len;i++)
  {
    ans = ans*10+s[i]-'0';
  }
  maxn = max(maxn,ans);
  //cout<<len<<" "<<k<<endl;
  if(wei == len || cao >= k) return;
  char sb = s[wei];
  for(int i = wei+1;i<len;i++)
  {
    if(s[i]>sb)
    {
      sb = s[i];
    }
  }
  if(sb == s[wei])
  {
    dfs_b(s,cao,wei+1);
    return;
  }
  else
  {
    for(int i = wei+1;i<len;i++)
    {
      if(s[i] == sb)
      {
        swap(s[i],s[wei]);
        dfs_b(s,cao+1,wei+1);
        swap(s[i],s[wei]);
      }
    }
  }
}
void dfs_s(string s,int cao,int wei)
{
  ll ans = 0;
  //cout<<s<<endl;
  for(int i = 0;i<len;i++)
  {
    ans = ans*10+s[i]-'0';
  }
  minn = min(minn,ans);
  if(wei == len || cao >=k) return;
  char sb = s[wei];
  for(int i = wei+1;i<len;i++)
  {
    if(s[i]<sb)
    {
      if(s[i] == '0' && wei == 0) continue;
      sb = s[i];
    }
  }
  //cout<<sb<<" "<<wei<<endl;
  if(sb == s[wei])
  {
    dfs_s(s,cao,wei+1);
    return;
  }
  else
  {
    for(int i = wei+1;i<len;i++)
    {
      if(s[i] == sb)
      {
        swap(s[i],s[wei]);
        dfs_s(s,cao+1,wei+1);
        swap(s[i],s[wei]);
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    string s;
  //  int k;
    cin>>s>>k;
  //  cout<<s<<k<<endl;
    len = s.length();
    //cout<<len<<" "<<k<<endl;
    ll ans = 0;
    for(int i = 0;i<len;i++)
    {
      ans = ans*10+s[i]-'0';
    }
    maxn = minn = ans;
    dfs_b(s,0,0);
    dfs_s(s,0,0);
    cout<<minn<<" "<<maxn<<endl;
  }
  return 0;
}
