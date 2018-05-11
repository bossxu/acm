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
int map[305][305];
int z[305][305];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);

   int t;
   cin>>t;
   int n;
   while(t--)
   {
     cin>>n;
     int a,b,c;
     clr(z,0);
     clr(map,0);
     for(int i = 1;i<=n*(n-1)/2;i++)
     {
       scanf("%d%d%d",&a,&b,&c);
       map[a][b] = c;
       map[b][a] = c;
     }
     for(int i = 1;i<=n;i++)
     {
       for(int j = i+1;j<=n;j++)
       {
         for(int k = j+1;k<=n;k++)
         {
           z[i][k] = max(map[i][j]+map[j][k],z[i][k]);
         }
       }
     }
     int maxn = 0;
     for(int i = 1;i<=n;i++)
     {
       for(int j = i+2;j<=n;j++)
       {
         maxn = max(z[i][j] + map[i][j],maxn);
       }
     }
     cout<<maxn<<endl;
   }
  return 0;
}
