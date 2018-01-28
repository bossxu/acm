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
const int maxn = 1e6+5;
struct node{
  int a,b;
}no[maxn];
int main()
{
  //freopen("/home/langman/桌面/in.txt","r",stdin);
  //freopen("/home/langman/桌面/out.txt","w",stdout);
   int n;
      while(cin >> n)
   {
     for(int i= 1;i<=n ;i++)
     {
       scanf("%d",&no[i].a);
     }
     ll m=0;
     ll ans=-1;
     int l=0,k;
     ll z=-1;
     for(int i=1;i<=n;i++)
     {
       scanf("%d",&no[i].b);
       if(z<0)
       {
         if(ans<m)
         {
           l=k;
           ans=m;
         }
         m=0;
         z=0;
         k=i;
       }
       m+=no[i].a;
       z+=no[i].a-no[i].b;
       //cout<<k<<endl;
     }
     if(z>=0)
     {
       for(int i=1;i<k;i++)
        {
          m+=no[i].a;
          z+=no[i].a-no[i].b;
          if(z<0 || i==k-1)
          {
            if(ans<m)
            {
              l=k;
              ans=m;
            }
            break;
          }
        }

     }

     printf("%d\n",l-1);
   }
  return 0;
}
