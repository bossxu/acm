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
ll n;
int m;
ll dp[20];
void cher(ll o)
{
//  cout<<o<<endl;
  while(o)
  {
    dp[o%m]++;
    o/=m;
  }
}
int main()
{
   while(cin>>n>>m)
   {
     clr(dp,0);
     int p = sqrt(n);
     for(int i = 1;i<=p;i++)
     {
       if(n%i == 0)
       {
         cher(i);
         if(i*i != n)
         cher(n/i);
       }
     }
     ll sum = 0;
     for(int i = 1;i<=15;i++)
     {
       //cout<<dp[i]<<endl;
       sum+=dp[i]*i*i;
     }
     int shu[100];
     int flag = 0;
     while(sum)
     {
       shu[flag++] = sum%m;
       sum/=m;
     }
     for(int i = flag -1;i>=0;i--)
     {
       if(shu[i]<=9) cout<<shu[i];
       if(shu[i]>=10) printf("%c",'A'+shu[i]-10);
     }
     cout<<endl;
   }
  return 0;
}
