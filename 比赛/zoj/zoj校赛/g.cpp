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
int map[100005];
int vis[100005][2];
int num[100005];
int st,en,item;
bool flag = 0;
int n,m;
struct node
{
  int a;
  int feet = 0;
  node(int c,int b)
  {
    a = c;
    feet = b;
  }
};
void bfs()
{
  int fang = map[st];
  vis[st][fang] = 0;
  queue<node>q;
  node i(st,0);
  q.push(i);
  while(!q.empty())
  {
    node s = q.front();
    q.pop();
    int z = s.a;
    int l = s.feet;
    //cout<<z<<endl;
    if(z == en)
    {
      flag = 1;item = min(item,l);
      continue;
    }
    int fang = map[z]+s.feet;
    fang = fang%2;
    //cout<<fang<<endl;
    if(vis[z][fang]) continue;
    vis[z][fang]=1;
    if(fang == 0)
    {
      node b(z+m,l+1),c(z-m,l+1);
      if(z+m<=n*m){q.push(b);}
      if(z-m>=1){q.push(c);}
    }
    if(fang == 1)
    {
      node b(z+1,l+1),c(z-1,l+1);
      if(z%m == 1)
      {
        if(m >= 2)
        q.push(b);
        continue;
      }
      if(z%m == 0)
      {
        if(m>=2)
        q.push(c);
        continue;
      }
      q.push(c);
      q.push(b);
    }
  }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   while(t--)
   {
     cin>>n>>m;
     clr(vis,0);
     clr(num,0);
     item = INF;
     flag = 0;
     for(int i = 1;i<=n;i++)
     {
       for(int j = 1;j<=m;j++)
       {
         scanf("%d",&map[(i-1)*m+j]);
       }
     }
     int s1,s2,e1,e2;
     scanf("%d%d%d%d",&s1,&s2,&e1,&e2);
     st = (s1-1)*m+s2,en = (e1-1)*m+e2;
     //cout<<st<<en;
     bfs();
     if(flag == 0) {cout<<"-1"<<endl;}
     else
     {
       cout<<item<<endl;
     }
   }
  return 0;
}
