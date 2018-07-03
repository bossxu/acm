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
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll long long
const int maxn = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
int shu[106];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
      ans+=shu[i];
    }
    ll op = 0;
    int  num = 0;
    for(int i = n;i>=1;i--)
    {
      op+=shu[i];
      num++;
      if(op>ans/2)
      {
        break;
      }
    }
    cout<<num<<endl;
  }
  return 0;
}
