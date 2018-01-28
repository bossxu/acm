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
const double eps = 1e-6;
const int maxn = 110000;
// 知识点分解：
int main()
{
    int n;
    int par[maxn],node[maxn],zi[maxn];
    while(cin>>n)
    {
      for(int i=1;i<=n;i++)
       {par[i]=i;node[i]=1;zi[i]=1;}
      for(int i=1;i<n;i++)
      {
          int a,b;
          cin>>a>>b;
          if(a>b)
          {
              int t;
              t=a,a=b,b=t;
          }
          par[b]=a;
          node[a]+=node[b];
          int k = b;
          while(par[a]!=a)
          {
              node[par[a]]+=node[k];
              a=par[a];
          }
          
      }
      int m;
      cin>>m;
      //for(int i=1;i<=n;i++) cout<<node[i]<<endl;
      while(m--)
      {
          char a;
          int z;
          getchar();
          scanf("%c%d",&a,&z);
          if(a=='Q')
          {
              printf("%d\n",node[z]);
          }
          else
          {
              int k;
              if(zi[z])
              k=-1;
              else
              k=1;
              zi[z]=!zi[z];
              node[z]+=k;
              while(par[z]!=z)
              {
                node[par[z]]+=k;
                z=par[z];
              }
          }
      }
    }
    return 0;
}