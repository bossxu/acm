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
const int maxn = 505;
int map[maxn][maxn];
int vis[maxn][maxn];
struct cao{
  int a,b,c;
}C[200005];
inline int read()// 可能这就是开挂b吧
{
    char k=0;char ls;ls=getchar();for(;ls<'0'||ls>'9';k=ls,ls=getchar());
    int x=0;for(;ls>='0'&&ls<='9';ls=getchar())x=x*10+ls-'0';
    if(k=='-')x=0-x;return x;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   while(t--)
   {
     clr(map,0);
     clr(vis,0);
     int n,q;
     cin>>n>>q;
     int num =  n*n;
     for(int i =1;i<=q;i++)
     {
       C[i].a = read(),C[i].b = read(),C[i].c =read();
     }
     for(int i =q;i>0 && num>0;i--)
     {
       int a =C[i].a,b =C[i].b,c=C[i].c;
       if(a==1)
       {
         for(int j = 1 ;j<=n;j++)
         {
           if(!vis[b][j])
           {
             num--;
             vis[b][j] = 1,map[b][j] = c;
           }
         }
       }
       if(a==2)
       {
         for(int j = 1;j<=n ;j++)
         {
           if(!vis[j][b])
           {
             num--;
             vis[j][b] = 1,map[j][b] =c ;
           }
         }
       }
     }
     for(int i = 1;i<=n;i++)
     {
       for(int j =1;j<n;j++)
         printf("%d ",map[i][j]);
         cout<<map[i][n]<<endl;
     }
   }
  return 0;
}
