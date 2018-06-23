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
int shu[1000005];
//首先sg函数是一个工具,我们要学会找规律
//其次每个题的sg函数只有一个定义,但是有很多的不同的sg求解方法
//sg有的是可以找规律,有的是需要本地记忆化的
//需要有所锻炼
int main()
{
  //  freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout;
   std::ios::sync_with_stdio(false);
  int t;
  cin>>t;
  int n;
  while(t--)
  {
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
      cin>>shu[i];
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    {
      if(shu[i]%4 == 0)
      {
        ans^=shu[i]-1;
      }
      else if(shu[i]%4 == 3)
      {
        ans^=shu[i]+1;
      }
      else
      ans^=shu[i];
    }
    if(ans == 0)
    {
      cout<<"Bob"<<endl;
    }
    else
    cout<<"Alice"<<endl;
  }

  return 0;
}
