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
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int vis[105],a[105];
   int n,m;
   while(cin>>n>>m)
   {
     for(int i =0;i<n;i++)
     {
       scanf("%d",&a[i]);
     }
     clr(vis,0);
     int k;
     cin>>k;
     while(k--)
     {
       int b ;
       scanf("%d",&b);
       vis[b] = 1;
     }
     int ans1,ans2,s=INF;
     for(int i = 0;i<=n-m;i++)
     {
       if(vis[i]) continue;
       int p = INF,z,q = a[i],j,l=1;
       for(j=1;l<m && j+i<n;j++)
       {
         if(vis[i+j])
         {
           continue;
         }
         l++;
         if(a[i+j]<p)
         {
           z = i+j;
           p = a[i+j];
         }
       }
       if(j+i>=n && l<m) break;
       else
       {
         if(s > q+p)
         {
           ans1 = i,ans2 = z;
           s = q+p;
         }
       }
     }
   cout<<ans1<<" "<<ans2;

   }
  return 0;
}
