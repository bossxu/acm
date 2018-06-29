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
ll shu[30];
ll C[505][505];
//这是一道基础容斥加数分解的题
//要注意什么时候去进行容斥，什么时候不需要。这取决与我当时的处理是否能直接处理掉
struct Node
{
  int k;
  int num;
  Node(){k = -1;}
  void init(int a,int b)
  {
    a = k;
    num = b;
  }
}node[1005],su[1005];
int tot;
void init()
{
  C[0][0] = 1;
  for(int i = 1;i<=500;i++)
  {
    C[i][0] = 1;
    C[i][i] = 1;
    for(int j = 1;j<i;j++)
    {
      C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
    }
  }
}
int cmp(Node a, Node b)
{
  return a.k<b.k;
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
   int n;
   init();
   while(cin>>n)
   {
     tot = 1;
     for(int i = 1;i<=n;i++)
     {
       cin>>shu[i];
       int m = shu[i];
       for(int j = 2;j*j<=m;j++)
       {
         if(m%j == 0)
         {
           int num = 0;
           while(m%j == 0)
           {
             num++;
             m/=j;
           }
           node[tot].k = j;
           node[tot++].num = num;
         }
       }
       if(m!=1)
       {
         node[tot].k = m;
         node[tot++].num = 1;
       }
     }
     sort(node+1,node+tot,cmp);
     int item = 1;
     su[1] = node[1];
     for(int i = 2;i<tot;i++)
     {
       if(su[item].k == node[i].k)
       {
         su[item].num+=node[i].num;
       }
       else
       {
         item++;
         su[item] = node[i];
       }
     }
     ll ans1 = 0;
     ll ans = 0;
     for(int i = 0;i<n;i++)
    {
      ans1 = 1;
      for(int j = 1;j<=item;j++)
     {
       ans1 = (ans1*C[n-i-1+su[j].num][n-i-1])%mod;
     }
     ans1 = ans1*C[n][i];
     if(i%2 == 0)
     {
       ans+=ans1;
     }
     else ans-=ans1;

     ans%=mod;
     }
     cout<<(ans+mod)%mod<<endl;;
   }
  return 0;
}
