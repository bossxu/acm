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
const int maxn = 100005;
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int shu[maxn];
   int t;
   cin>>t;
   shu[0]=0;
   int vis[maxn];
   while(t--)
   {
     int n;
     cin>>n;
     for(int i=1;i<=n;i++)
     {
       scanf("%d",&shu[i]);
       vis[i]=0;
       if(shu[i]<shu[i-1])
       {
         vis[i]=1,vis[i-1]=1;
       }
     }


   }
  return 0;
}
