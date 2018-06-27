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
char map[55][55];
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
   int n,m;
   while(cin>>n>>m)
   {
     for(int i = 1;i<=n;i++)
     {
       if(i%2)
       {
         for(int j = 1;j<=m;j++)
         {
           map[i][j] = '#';
         }
       }
       else
       {
         for(int j = 1;j<=m;j++)
         {
           map[i][j] = '.';
         }
         if(i%4 == 0)
         {
           map[i][1] ='#';
         }
         else
         map[i][m] = '#';
       }
     }
     for(int i = 1;i<=n;i++)
     {
       for(int j = 1;j<=m;j++)
       {
         cout<<map[i][j];
       }
       cout<<endl;
     }
   }
  return 0;
}
