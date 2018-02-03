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
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
//欧拉函数 求的是 1 -> n-1 中与n 互质的数的个数
ll phi(ll n)
{
  ll rea = n;
    for(int i = 2;i*i<=n;i++)
    if(n%i == 0)
    {
      rea = rea - rea/i;
      do n/=i;
      while(n%i == 0);
    }
    if(n>1)
    rea = rea - rea/n;
  return rea;
}

int main()
{
   ll n;
   int t;
   cin>>t;
   while(t--)
   {
     cin>>n;
     cout<<phi(n)<<endl;
   }
  return 0;
}
