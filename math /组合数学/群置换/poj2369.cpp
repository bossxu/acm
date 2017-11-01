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
int gcd(int a,int b)
{
  return a%b==0?b:gcd(b,a%b);
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);

   int n ;
   int a[1005];
   bool vis [1005];
   while(cin>>n)
   {
     int ans = 1;
     for(int i = 1;i<=n;i++)
      {
        scanf("%d",&a[i]);
      }
     clr(vis,0);
     for(int i=1;i<=n;i++)
     {
       if(vis[i]) continue;
       vis[i] = 1;
       int num = 1;
       int k = a[i];
       while(!vis[k])
       {
         vis[k] = 1;
         k = a[k];
         //cout<<k<<"-->"<<a[flag][i]<<endl;
         num++;
       }
       ans  = ans*num/gcd(ans,num);
     }
        cout<<ans<<endl;
   }
  return 0;
}
