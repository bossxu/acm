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
// 倒过来跑并查集
//新方法get
//草害我debug一个小时
struct Node
{
  int x0,y0;
  int x1,y1;
  int ans;
}node[10005];
int cnt[1005][1005];
int vis[1005][1005];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int n,m,q;
const int maxn = 1e6+10;
int f[maxn];
void init()
{
  for(int i = 0;i<maxn;i++)
  {
    f[i] = i;
  }
}
int idx(int i,int j)
{
  return (i-1)*m+j;
}
int find(int x)
{
  if(f[x] == x) return x;
    f[x] = find(f[x]);
    return f[x];
}
bool unit(int x,int y)
{
  x = find(x),y = find(y);
  if(x == y)
    return 0 ;
  f[x] = y;
  return 1;
}
void dfs(int x,int y)
{
  vis[x][y] = 1;
  for(int i = 0;i<4;i++)
  {
    int tx = x+dx[i];
    int ty = y+dy[i];
    if(tx<=0 || ty<=0 || tx>n || ty>m) continue;
    if(vis[tx][ty] || cnt[tx][ty] != 0) continue;
    //cout<<tx<<" "<<ty<<endl;
      unit(idx(x,y),idx(tx,ty));
      dfs(tx,ty);
  }
}
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
   while(cin>>m>>n>>q)
   {
     init();
     clr(vis,0);
     clr(cnt,0);
     for(int i = 1;i<=q;i++)
     {
       cin>>node[i].y0>>node[i].x0>>node[i].y1>>node[i].x1;
       for(int j = node[i].x0;j<=node[i].x1;j++)
       {
         for(int k = node[i].y0;k<=node[i].y1;k++)
         {
           cnt[j][k]++;
         }
       }
     }
     int res = 0;
     for(int i = 1;i<=n;i++)
     {
       for(int j = 1;j<=m;j++)
       {
         if(!vis[i][j] && cnt[i][j] == 0)
         {
           res++;
           dfs(i,j);
         }
       }
     }
     node[q].ans = res;
    // cout<<"hello"<<endl;
     for(int i = q;i>1;i--)
     {
       for(int j = node[i].x0;j<=node[i].x1;j++)
       {
         for(int k = node[i].y0;k<=node[i].y1;k++)
         {
           cnt[j][k]--;
           if(cnt[j][k]) continue;
           res++;
           for(int l = 0;l<4;l++)
           {
             int tx = j+dx[l];
             int ty = k+dy[l];
             if(tx<=0 || ty<=0 || tx>n || ty>m) continue;
             if(cnt[tx][ty]!=0) continue;
             if(unit(idx(j,k),idx(tx,ty)))
             {
               res--;
             }
           }
         }
       }
       node[i-1].ans = res;
     }
     for(int i = 1;i<=q;i++)
     {
       cout<<node[i].ans<<endl;
     }

   }
  return 0;
}
