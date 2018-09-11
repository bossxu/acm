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
int vis[45005];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin>>n)
  {
    clr(vis,0);
    if(n == 1) {cout<<"No"<<endl;continue;}
    if(n == 2) {cout<<"No"<<endl;continue;}
    else
    {
      int op;
      if(n%2)
        op = n/2+1;
      else
        op = n/2;
        vis[op] = 1;
      cout<<"Yes"<<endl;
      cout<<1<<" "<<op<<endl;
      cout<<n-1;
      for(int i = 1;i<=n;i++)
      {
        if(vis[i]) continue;
        cout<<" "<<i;
      }
      cout<<endl;
    }
  }
  return 0;
}
