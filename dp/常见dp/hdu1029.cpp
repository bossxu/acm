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
int vis[1000005];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
   int n;

   while(cin>>n)
   {
     clr(vis,0);
     int a;
     for(int i = 1;i<=n;i++)
     {
       cin>>a;
       vis[a]++;
     }
     for(int i = 1;i<=100000;i++)
     {
       if(vis[i]>n/2)
       {
         cout<<i<<endl;
         break;
       }
     }
   }
  return 0;
}
