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
char map[105][105];
int n,m;
int check(int i,int j)
{
  if(i<0 || i == n || j<0 || j==m) return 0;
  if(map[i][j] == '*') return 1;
  return 0;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  while(cin>>n>>m)
  {
    for(int i = 0;i<n;i++)
    {
      cin>>map[i];
    }
    bool flag = 1;
    for(int i = 0;i<n;i++)
    {
      for(int j = 0;j<m;j++)
      {
          int ans = 0;
          int item = map[i][j] == '.'?0:map[i][j]-'0';
          if(map[i][j] == '.') item = 0;
          if(map[i][j] == '*') continue;
          for(int x = -1;x<=1;x++)
          {
            for(int y = -1;y<=1;y++)
            {
              if(x==0 && y == 0)
              {
                continue;
              }
              ans+=check(i+x,y+j);
              //cout<<check(i+x,y+j)<<endl;
            }
          }
          //cout<<i<<" "<<j<<" "<<ans<<" "<<item<<endl;
          if(ans!=item) flag = 0;
      }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

  }


  return 0;
}
