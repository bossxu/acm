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
int map[505][505];
int main()
{
   int n,m;
   while(cin>>n>>m)
   {
     for(int i = 1;i<=m;i++)
     {
       int a,b;
       cin>>a>>b;
       map[a][b] = 1;
     }
     for(int i = 1;i<=n;i++)
     {
       for(int j = i+1;j<=n;j++)
       {
         for(int k = i+1; k<j;j++)
         {
           map[i][j] = map[i][k]&&map[k[j]]
         }
       }
     }
   }
  return 0;
}
