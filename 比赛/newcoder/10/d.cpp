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
int main()
{
   int n,m;
   cin>>n>>m;
   char s[105];
   scanf("%s",s);
   for(int i = 1;i<=m;i++)
   {
     int a,b;
     char c,d;
     cin>>a>>b>>c>>d;
     for(int j = a-1;j<=b-1;j++)
     {
       if(s[j]==c)
       {
         s[j] = d;
       }
     }
   }
   printf("%s\n",s);
  return 0;
}
