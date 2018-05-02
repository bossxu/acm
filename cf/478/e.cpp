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
struct Node
{
  ll x,y;
  ll ans;
}node[200005];
int cmp(Node a,Node b)
{
  if(a.ans == b.ans) return a.x<b.x;
  return a.ans < b.ans;
}
int main()
{
   int n;
   ll a,b;
   while(cin>>n>>a>>b)
   {
     ll op;
     for(int i = 1;i<=n;i++)
     {
       cin>>op>>node[i].x>>node[i].y;
       node[i].ans = a*node[i].x-node[i].y;
     }
     sort(node+1,node+1+n,cmp);
     ll ans = 0;
     int flag = 1,k=1,l=1;
     for(int i = 2;i<=n;i++)
     {
       //cout<<l<<endl;
       //cout<<node[i].x<<endl;
       if(node[i].ans!=node[i-1].ans || i == n)
       {
         if(i == n || node[i].ans == node[i-1].ans) k++;
         ans += k*l;
         l = 1;
         k = 1;
       }
       else
       {
         //cout<<flag<<endl;
         if(node[i].x == node[i-1].x)
         {
           flag++;
         }
         else
         {
           k++;
           l*=flag;
           //cout<<l<<endl;
           flag = 1;
         }
       }
     }
     cout<<ans*2<<endl;
   }
  return 0;
}
