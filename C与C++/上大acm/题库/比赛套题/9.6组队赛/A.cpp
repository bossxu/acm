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
const int maxn = 60005;
int N;
struct st{
  int x,y;
}pos[maxn];
int t[maxn];
int lowbit(int x)
{
    return x&(-x);
}
void change(int x,int p)//将第x个数加p
{
    while(x<=N)
    {
        t[x]+=p;
        x+=lowbit(x);
    }
    return;
}
bool cmp(st a, st b)
{
  if(a.y==b.y)
       return a.x>b.x;
   return a.y<b.y;
}
ll sum(int k)//前k个数的和
{
    ll ans=0;
    while(k>0)
    {
        ans+=t[k];
        k-=lowbit(k);
    }
    return ans;
}
int main()
{
   int z;
   cin>>z;
   int co=0;
   while(z--)
   {
       clr(t,0);
       int n,k;
       scanf("%d%d",&n,&k);
       N=n+k;
       for(int i=1;i<=n;i++)
           scanf("%d%d",&pos[i].x,&pos[i].y);
       for(int i=1;i<=k;i++)
           scanf("%d%d",&pos[i+n].x,&pos[i+n].y);
       sort(pos+1,pos+n+k+1,cmp);
       long long ans=0;
       for(int i=1;i<=n+k;i++)
       {
           change(pos[i].x,1);
           ans+=pos[i].x-sum(pos[i].x);
       }
       printf("Scenario #%d:\n%lld\n",++co,ans);
       if(z!=1) printf("\n");
   }
  return 0;
}
