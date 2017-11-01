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
#include<map>
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
int a[1005][1005];
int n,k;
bool check(int x)
{
  int flag = 1;
  for(int i = 1;i<=n;i++)
   if(a[x][i] != a[0][i])
    flag = 0;
//cout<<x<<" "<<flag<<endl;
   return !flag;
}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

   while(cin>>n>>k)
   {
     for(int i = 1;i<=n;i++)
     {
       scanf("%d",&a[0][i]);
     }
     int m = 0;
    while(m==0 || check(m))
    {
      m++;
      for(int i = 1;i<=n;i++)
      {
        a[m][i] = a[m-1][a[m-1][i]];
      }
      for(int i = 1;i<=n;i++)
       cout<<a[m][i]<<",";
       cout<<endl;
    }
    //cout<<m<<endl;
    k%=m;
    k = m-k;
    for(int i = 1;i<=n;i++)
    {
      cout<<a[k][i]<<endl;
    }
   }
  return 0;
}
