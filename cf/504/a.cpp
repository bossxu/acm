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
string a,b;
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,m;
  while(cin>>n>>m)
  {
    cin>>a>>b;
    int st = -1;
    for(int i = 0;i<n;i++)
    {
      if(a[i] == '*')
      st  = i;
    }
    if(st == -1)
    {
      int flag = n==m?1:0;
      for(int i = 0;i<n;i++)
      {
        if(a[i]!=b[i])
        flag = 0;
      }
      if(flag) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
    else
    {
      int flag = n<=m+1?1:0;
      //cout<<flag<<endl;
      for(int i = 0;i<st;i++)
      {
        if(a[i]!=b[i]) flag = 0;
      }
      //cout<<flag<<endl;
      for(int i = n-1;i>st;i--)
      {
        int k = n-i;
        //cout<<k<<endl;
        if(a[i]!=b[m-k])
        {
          flag = 0;
        }
      }
      if(flag) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
  }
  return 0;
}
