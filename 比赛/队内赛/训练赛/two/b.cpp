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
void init()
{
  C[0][0] = 1;
  for(int i = 1;i<=500;i++)
  {
    C[i][0] = 1;
    C[i][i] = 1;
    for(int j = 1;j<i;j++)
    {
      C[i][j] = (C[i][j-1]+C[i-1][j])%mod;
    }
  }
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
   int n;
   while(cin>>n)
   {
     int num = 0;
     for(int i = 1;i<=n;i++)
     {
       cin>>shu[i];
       int m = shu[i];
       for(int j = 2;j<=(int)(sqrt(shu[i]));j++)
       {
         if(j>m)
         {
           break;
         }
         while(m%j == 0)
         {
            m/=j;
            num++;
         }
       }
       if(m!= 1) num++;
     }
     cout<<num<<endl;
   }
  return 0;
}
