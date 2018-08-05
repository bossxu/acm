#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
//#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll long long
const int maxn = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
ll map[105][105];
ll row[105];
ll clr[105];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,m;
  while(cin>>n>>m)
  {
    ll r = 0;
    for(int i = 1;i<=n;i++)
    {
      cin>>row[i];
      r^=row[i];
    }
    ll c = 0;
    for(int i = 1;i<=m;i++)
    {
      cin>>clr[i];
      c^=clr[i];
    }
    if(c!=r)
    {
      cout<<"NO"<<endl;
      continue;
    }
    cout<<"YES"<<endl;
    ll t = clr[m]^row[n]^c;
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        if(i == n && j == m)
        {
          cout<<t<<" ";
        }
        else if(i == n && j != m)
        {
          cout<<clr[j]<<" ";
        }
        else if(i !=n && j==m)
        {
          cout<<row[i]<<" ";
        }
        else
        cout<<0<<" ";
      }
      cout<<endl;
    }

  }
  return 0;
}
