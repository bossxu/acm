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
typedef unsigned long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
struct node
{
 int a,x,y,z;
}no[55];
int shu[100];
int dp[100];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
  int n;
  while(cin>>n)
  {
    clr(dp,0);
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    int q;
    cin>>q;
    for(int i = 1;i<=q;i++)
    {
      cin>>no[i].a>>no[i].x>>no[i].y;
      if(no[i].a) cin>>no[i].z;
    }
    for(int i = 1;i<=q;i++)
    {
       if(!no[i].a) shu[no[i].x] = no[i].y;
    }
    for(int i = 1;i<=n;i++) dp[i] = shu[i];
    for(int i = 1;i<=q;i++)
    {
      if(no[i].a)
      {
        int item = no[i].x;
        int left = min(no[i].y,no[i].z);
        int right = max(no[i].y,no[i].z);
        for(int j = left;j<=right;j++)
        {
          dp[item]+=shu[j];
        }
        if(item>=left && item<=right) dp[item]-=shu[item];
      }
    }
    int minn = INF;
    for(int i = 1;i<=n;i++)
    {
      minn = min(dp[i],minn);
    }
    cout<<minn<<endl;
  }
  return 0;
}
