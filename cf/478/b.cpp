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
#define mod 1e9+7
#define pi acos(-1)
#define loge exp(1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
ll shu[20];
ll op[20];
int main()
{
  for(int i = 1;i<14;i++)
  {
      cin>>shu[i];
  }
  cin>>shu[0];
  ll ans = 0;
  for(int i = 0;i<14;i++)
  {
    clr(op,0);
    ll flag = 0;
    for(int j = 1;j<=14;j++)
    {
      op[j] = shu[i]/14;
    }
    int z = shu[i]%14;
    for(int j = 1;j<=z;j++)
    {
      op[j]++;
    }
    for(int j = 1;j<=14;j++)
    {
      //cout<<op[j]<<" ";
      int index = (j+i)%14;
      if(j == 14 ) {if(op[j]%2 == 0) flag+=op[j];}
      else if((op[j]+shu[index])%2==0) flag+=op[j]+shu[index];
    }
    //cout<<endl;
    ans = max(ans,flag);
  }
  cout<<ans<<endl;
  return 0;
}
