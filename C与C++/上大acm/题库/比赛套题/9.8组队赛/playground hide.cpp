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
int N;
const int maxn=10005;
const double eps = 1e-6;
int dist[maxn];
bool visit[maxn];
//知识点: 在于用一个结构体来解决 当结点过多的操作
//链接表存不下的情况
//
struct node
{
    int v;//终点
    int w;//权
    node(){};
    node(int x,int y):v(x),w(y){}
    bool operator <(const node &cp)const
    {
        return w > cp.w;
    }
};
vector<node>route[maxn];
priority_queue<node>que;
void init()
{

    for(int i=0;i<=N;i++)
    {
        route[i].clear();
        visit[i]=0;
    }
    visit[0]=1;
    while(!que.empty())
          que.pop();
}
void solve()
{
    int x,y;
    while(!que.empty())
    {
        node tmp = que.top();
        que.pop();
        if(visit[tmp.v])
           continue;
        visit[tmp.v] = 1;
        dist[tmp.v] = tmp.w;
        for(int i = 0;i < route[tmp.v].size();i ++)
        {
            x = route[tmp.v][i].v;
            y = route[tmp.v][i].w;
            if(dist[x] > tmp.w+y)
            {
                dist[x] = tmp.w+y;
                que.push(node(x,dist[x]));
            }
        }
    }
}
int main()
{
   int t;
   int n,p;
   cin>>t;
   int co=0;
   while(t--)
   {
     cin>>n>>p;
     N=n;
     init();
     for(int i=1;i<=n;i++)
     {
       int a;
       scanf("%d",&a);
       dist[i]=a;
     }
     for(int i=1;i<=p;i++)
     {
        int a,b,c,d;
         scanf("%d%d%d%d",&a,&b,&c,&d);
        route[a+1].push_back(node(b+1,c));
        route[b+1].push_back(node(a+1,d));
     }
     for(int i = 1;i <= n;i ++)
         que.push(node(i,dist[i]));

      solve();
      int m=0,k=0;
      for(int i=1;i<=n;i++)
        if(dist[i]>m)
        {
          m=dist[i],k=i-1;
        }
        printf("Scenario #%d:\n",++co);
        printf("%d\n\n",k);
   }
  return 0;
}
