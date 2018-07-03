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
char s[300005];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n,x,y;
  while(cin>>n>>x>>y)
  {
    cin>>s;
    int tot = 0;
    int flag = 0;
    for(int i = 0;i<n;i++)
    {
      if(s[i] == '0')
      {
        if(!flag) {flag = true;tot++;}
      }
      else
        flag = false;
    }
    if(!tot)
    {
      cout<<0<<endl;
      continue;
    }
    if(x>y)
    {
      cout<<1LL*y*tot<<endl;
    }
    else
    {
      cout<<1LL*(tot-1)*x + 1LL*y<<endl;
    }
  }
  return 0;
}
