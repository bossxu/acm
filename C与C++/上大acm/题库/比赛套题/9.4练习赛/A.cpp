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
int n;
const int maxn=20005;
const double eps = 1e-6;
int ansi,ansb;
// 知识点分解：前向星建图，树形dp,求树的重心 poj 1655
struct edge{
    int to,next;
}E[maxn<<1];
int head[maxn],cnt;
void init()
{
    clr(head,-1);
    cnt=0;
    ansi=ansb=INF;
}
int add(int a,int b)
{
    E[cnt].to=b;
    E[cnt].next=head[a];
    head[a]=cnt++;
}
int dfs(int x, int fa)
{
   int sum=1;
   int bx=0,t;
   for(int i=head[x];i!=-1;i=E[i].next)
   {
       if(E[i].to==fa) continue;
       t=dfs(E[i].to,x);
       bx=max(bx,t);
       sum+=t;
   }
   bx=max(n-sum,bx);
   if(bx<ansb || (bx==ansb && ansi>x))
   {
       ansi=x,ansb=bx;
   }
   return sum;
}

int main()
{
    int t;
    cin>>t;
    while(cin>>n)
    {
        init();
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            add(a,b);
            add(b,a);
        }
     dfs(1,-1);
     printf("%d%d\n",ansi,ansb);
    }
    return 0;
}
