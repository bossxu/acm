#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int shu[106];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n;
  while(cin>>n)
  {
    for(int i = 1;i<=n;i++)
    {
      char s;
      cin>>s;
      if(s == '1') shu[i] = 1;
      else shu[i] = 0;
    }
    int flag = 1;
    shu[0] = 100;
    shu[n+1] = 100;
    for(int i = 1;i<=n;i++)
    {
      if(shu[i] == 1)
      {
        if(shu[i-1] == 1 || shu[i+1] == 1) flag =0;
      }
      if(shu[i] == 0)
      {
        if(shu[i-1] == 0 && shu[i+1] == 0) flag = 0;
      }
    }
    if(shu[1] == 0 && shu[2] == 0) flag = 0;
    if(shu[n] == 0 && shu[n-1] == 0) flag = 0;
    if(shu[1] == 0 && n == 1) flag = 0;

    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}
