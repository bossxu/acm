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
const int maxn = 1e5+5;
struct Edge{
  int to,next;
}edge[2*maxn*10];
int head[maxn],tot;
void add(int u,int v)
{
  edge[tot].to = v;
  edge[tot].next = head[u];
  head[u] = tot++;
}
ll dp[maxn],sum,ans;

void dfs(int u,int father)
{
  //cout<<"  ---"<<u<<endl;
  for(int i=head[u];i!=-1;i=edge[i].next)
  {
    int v = edge[i].to;
    if(father != v)
    {
      dfs(v,u);
    dp[u]+=dp[v];
  }
  }
  ll c = sum-dp[u]-dp[u];
  //cout<<c<<endl;
  c = c>0?c:-c;
  ans = min(ans,c);
}

int main()
{
  /*freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);*/
   int n,m;
   int cou = 0;
   while(cin>>n>>m && (n!=0 || m!=0))
   {
     clr(head,-1);
      sum = 0;
      tot = 0;
     for(int i = 1;i<=n;i++)
     {
       scanf("%lld",&dp[i]);
       sum+=dp[i];
     }
     ans = sum;
     for(int i =1;i<=m;i++)
     {
       int a,b;
       scanf("%d%d",&a,&b);
       add(a,b);
       add(b,a);
     }
     dfs(1,-1);
     printf("Case %d: %lld\n",++cou,ans);
        }
  return 0;
}
