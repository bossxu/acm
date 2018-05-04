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
const int MAXN = 10000+10;
int N;//总结点数
int root,now;
ll ans;
struct Edge//存边
{
  int to,val;
  Edge(int a,int b = 1)
  {
    to = a,val = b;
  }
};
vector<Edge>G[MAXN];
int son[MAXN],maxson[MAXN];
bool check[MAXN];
int dis[MAXN];
int k;
void getroot(int v,int pa)
{
  son[v] = 1;maxson[v] = 0;
  for(int i = 0;i<G[v].size();i++)
  {
      int t = G[v][i].to;
      if(pa == t) continue;
      getroot(t,v);
      son[v] += son[t];
      maxson[v] = max(maxson[v],son[t]);
  }
    maxson[v] = max(maxson[v],N-son[v]);
    root = maxson[v]<maxson[root]?v:root;
}
void getdis(int tr,int pa,int dist)
{
  dis[now++] = dist;
  for(int i = 0;i<G[tr].size();i++)
  {
    int t = G[tr][i].to;
    int va = G[tr][i].val;
    if(t == pa || check[t]) continue;
    getdis(t,tr,dist+va);
  }
}

int slove(int tr,int dist)//这里是获取以这个点为根结点的,所有满足情况数
{
    now = 0;
    clr(dis,0);
    getdis(tr,-1,dist);
    sort(dis,dis+now);
    int l = 1,r = now-1,tep = 0;
    while(l<=r)
    {
      if(dis[l]+dis[r]<=k) {tep += r-l;l++;}
      else r--;
    }
    return tep;

}
void Divide(int tr) //分治的关键代码
{
  ans += slove(tr,0);
  check[tr] = true;
  for(int i = 0;i<G[tr].size();i++)
  {
    int t = G[tr][i].to;
    int va = G[tr][i].val;
    if(check[t]) continue;
    ans-=slove(t,va);
    N = son[t];root = 0;
    maxson[root] = INF;
    getroot(t,0);
    Divide(t);
  }

}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int n;
  while(cin>>n>>k)
  {
    if(!n && !k) break;
    
  }

  return 0;
}
