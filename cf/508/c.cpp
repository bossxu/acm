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
ll a[100005];
ll b[100005];
int cmp(int c,int d)
{
  return c>d;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      cin>>a[i];
    }
    for(int i = 1;i<=n;i++)
    {
      cin>>b[i];
    }
    int st1=1,st2=1;
    sort(a+1,a+n+1,cmp);sort(b+1,b+n+1,cmp);
    int end = 2*n;
    int flag = 0;
    ll ans1 = 0,ans2 = 0;
    while(flag <= end)
    {
      flag++;
      if(flag%2)
      {
        if(st1 > n)
        {
          st2++;
          continue;
        }
        if(st2 > n)
        {
          ans1 += a[st1++];
          continue;
        }
        if(a[st1] > b[st2])
        {
          ans1 += a[st1];
          st1++;
        }
        else
        {
          st2++;
        }
      }
      else
      {
        if(st1 > n)
        {
          ans2+=b[st2++];
          continue;
        }
        if(st2 > n)
        {
          st1++;
          continue;
        }
        if(b[st2] > a[st1] )
        {
            ans2+=b[st2++];
        }
        else
        {
          st1++;
        }
      }
    }
    cout<<ans1-ans2<<endl;
  }
  return 0;
}
