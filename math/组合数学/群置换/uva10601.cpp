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
int a[15];
int cun[15];
ll c[15][15];
/*
终于找到了一个 用到polya定理的题
他的步骤  1: 在于找到每个置换,不能漏,找到有多少种转换的方式
        2:找到每种置换的不动点 这样的目的在于找到在每个循环中它都需要保证他们的颜色是相同的
        3;根据给的条件来算出,有多少种情况符合 循环的颜色相同(前提)
        4:如果在这个循环中满足这个条件 , 有这个颜色的数目相同,那么他就是合法的
        5:有点意思
*/
void trans();
void init()
{
  c[1][1] = 1;
  for(int i = 0;i<=12;i++)
  {
    c[i][0] = 1,c[i][i] = 1;
    for(int j = 1;j<i;j++)
    {
      c[i][j] = c[i-1][j]+c[i-1][j-1];
    }
  }
}
ll slove(int x)
{
   int n = 0;
   ll sum = 1;
   for(int i = 1;i<=6;i++)
   {
     if(cun[i]%x == 0)
     {
       cun[i]/=x;
       n+=cun[i];
     }
     else
     return 0;
   }
     for(int i = 0;i<6;i++)
     {
       sum*=c[n][cun[i]];
       n-=cun[i];
     }
   return sum;
}
ll Ans()
{
  ll ans = 0;
  trans();
  ans += slove(1);
  trans();
  ans += slove(3)*8;
  trans();
  ans += slove(4)*6;
  trans();
  ans += slove(2)*3;
  for(int i = 1;i<=6;i++)
  {
    for(int j =1 ;j<=6;j++)
    {
      trans();
      cun[i]--,cun[j]--;
      if(cun[i]<0||cun[j]<0) continue;
      ans+=6*slove(2);
    }
  }
  return ans/24 ;
}

void trans()
{
  for(int i = 1;i<=6;i++)
  {
    cun[i] = a[i];
  }
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   init();
   while(t--)
   {
     int y;
     clr(a,0);
     for(int i = 1;i<=12;i++)
     {
       cin>>y;
       a[y]++;
     }
     cout<<Ans()<<endl;
   }
  return 0;
}
