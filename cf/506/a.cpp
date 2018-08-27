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
char s[5000];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,k;
  while(cin>>n>>k)
  {
    cin>>s;
    int st = n;
    for(int i = 0;i<n;i++)
    {
      for(int j = i+1;j<n;j++)
      {
        int flag = 1;
        for(int k = i,l = j;l<n;l++,k++)
        {
          if(s[k] != s[l])
          flag = 0;
        }
        if(flag)
        st = min(st,j);
      }
      if(st!=n) break;
    }
  //  cout<<"hello"<<endl;
    cout<<s;
    for(int i = 1;i<=k-1;i++)
    {
        for(int j = n-st;j<n;j++)
        {
          cout<<s[j];
        }
    }
    cout<<endl;
  }
  return 0;
}
