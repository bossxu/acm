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
#define pb push_back
//这题一开始我读错了题
//这题的意思不仅是要知道改变几个点
//还要知道改变的是哪几个点
//不过这题的问题的关键点还不仅在于那个求每个点的权值
//还在于我们需要知道是哪几个点的处理造成了这样的后果
//题解的巧妙处在于那个他证明了一个点就是,一个是叶子结点的值是确定的,然后更巧妙的是他知最多也只有两个点的,也就是必定存在两个数使得其gcd为1
//这题给我们提了个醒,确实有时候需要去思考有没有什么不确定的东西我没有考虑到
//好题,很巧妙的一个思想
int n;
int shu[100005];
ll dp[100005];
vector<int>op[100005];
ll dep[100005];
ll son[100005];
int p[100005];
void dfs(int st,int pre)
{
  ll x = 0,y = 0;
  dep[st] = pre==-1?0:dep[pre]+1;
  p[st] = pre;
  son[st] = 1;
  for(int i = 0;i<op[st].size();i++)
  {
    int v = op[st][i];
    if(v == pre) continue;
    dfs(v,st);
    son[st]+=son[v];
    if(x == 0)
    {
      x = son[v];
    }
    else
    {
      y = son[v];
    }
  }
  int z = n-1-x-y;
  dp[st] = x*y + x*z + y*z;
  dp[st] += n-1;
  dp[st] *= 2;
  dp[st] +=1;
}
void slove()
{
  ll s = 0;
  for(int i = 1;i<=n;i++)
  {
    s +=  dp[i]*shu[i];
  }
  if(s == 0)
  {
    printf("0\n");
    return;
  }
  for(int i = 1;i<=n;i++)
  {
    if(s%dp[i] == 0)
    {
      printf("1 %d\n",i);
      return;
    }
  }
  int tot = 1;
  for(int i = 1;i<=n;i++)
  {
    if(dep[i]>dep[tot])
    tot = i;
  }
  printf("2 %d %d\n",tot,p[tot]);
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  // std::ios::sync_with_stdio(false);
  // cin.tie(0);
  // cout.tie(0);
  int t;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    clr(dp,0);
    clr(son,0);
    clr(p,0);
    for(int i = 1;i<=n;i++)
    {
      op[i].clear();
      scanf("%lld",&shu[i]);
    }
    for(int i = 1;i<n;i++)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      op[a].pb(b);
      op[b].pb(a);
    }
    dfs(1,-1);
    slove();
  }

  return 0;
}
