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
ll shu[2005];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int n,k;
   while(cin>>n>>k)
   {
     for(int i = 1;i<=n;i++)
     {
       cin>>shu[i];
     }
     shu[0] = 0;
     cout<<shu[1];
     for(int i = 2;i<=n;i++)
     {
       shu[i] += (shu[i-1]*k)%mod;
       cout<<" "<<shu[i];
     }
     cout<<endl;
   }
  return 0;
}
