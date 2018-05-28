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
struct Node
{
  int minn,maxn;
  int h;
}node[100];
int cmp(Node a,Node b)
{
  if(a.maxn == b.maxn)
  {
    return a.minn<b.minn;
  }
  return a.maxn<b.maxn;
}
int dp[100];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
   int n;
   int flag = 1;
   while(cin>>n)
   {
     if(!n) break;
     clr(dp,0);
     int a,b,c;
     for(int i = 1;i<=n;i++)
     {
       cin>>a>>b>>c;
       node[i].minn = min(a,b),node[i].maxn = max(a,b),node[i].h = c;
       node[i+n].minn = min(a,c),node[i+n].maxn = max(a,c),node[i+n].h = b;
       node[i+2*n].minn = min(b,c),node[i+2*n].maxn = max(b,c),node[i+2*n].h = a;
     }
     sort(node+1,node+3*n+1,cmp);
     clr(dp,0);
     int op = 0;
     for(int i = 1;i<=3*n;i++)
     {
       dp[i] = node[i].h;
       int maxnn = 0;
       for(int j = 1;j<i;j++)
       {
         if(node[i].minn > node[j].minn && node[i].maxn>node[j].maxn)
         {
           maxnn = max(maxnn,dp[j]);
         }
       }
       dp[i] += maxnn;
       op = max(op,dp[i]);
     }
     cout<<"Case "<<flag++<<": maximum height = ";
     cout<<op<<endl;
   }
  return 0;
}
