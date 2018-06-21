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
#define clr(a,x) memset(a,x,sizeof(a))
int  s[2005][2005];
int ans[2005];
int n,m;
bool check()
{
  for(int i = 0;i<m;i++)
  {
    if(ans[i]==0) return false;
  }
  return true;
}
int main()
{
  std::ios::sync_with_stdio(false);
  char ko[2005];
  while(cin>>n>>m)
  {
    clr(ans,0);
    for(int i = 0;i<n;i++)
    {
      cin>>ko;
      //cout<<ko<<endl;
      for(int j =0;j<m;j++)
      {
        s[i][j] = ko[j]-'0';
        ans[j] += s[i][j];
      }
    }

    int flag = 0;
    for(int i = 0;i<n;i++)
    {
      for(int j = 0;j<m;j++)
      {
        ans[j] = ans[j]-s[i][j];
      }
       if(check())
       {
         flag = 1;
       }
      for(int j = 0;j<m;j++)
      {
        ans[j] = ans[j]+s[i][j];
      }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
