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
int main()
{
   int shu[3][3];
   for(int i =0;i<3;i++)
   {
     for(int j =0;j<3;j++)
     {
       cin>>shu[i][j];
     }
   }
   for(int i = 0;i<3;i++)
   {
    printf("%d %d %d\n",shu[0][i],shu[1][i],shu[2][i]);
   }
  return 0;
}
