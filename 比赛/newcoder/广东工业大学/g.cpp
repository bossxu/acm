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
char lala(char z)
{
  if(z == '+') return '+';
  if(z =='-') return '|';
  if(z =='|') return '-';
  return 'SB';
}
int main()
{
   char map[36][36];
   int t;
   cin>>t;
   char s[1005];
   while(t--)
   {
     int n,m;
     cin>>n>>m;
     for(int i = 1;i<=n;i++)
     {
       for(int j = 1;j<=m;j++)
       {
         cin>>map[i][j];
       }
     }
     cin>>s;
     int num=0;
     for(int i = 0;i<strlen(s);i++)
     {
       if(s[i] == 'L') num+=3;
       else num+=1;
     }
     num%=4;
     if(num == 0)
     {
       cout<<n<<" "<<m<<endl;
       for(int i = 1;i<=n;i++)
       {
         for(int j = 1;j<=m;j++)
         {
           cout<<map[i][j];
         }
         cout<<endl;
       }
     }
     if(num == 2)
     {
       cout<<n<<" "<<m<<endl;
       for(int i = n;i>=1;i--)
       {
         for(int j = m;j>=1;j--)
         {
           cout<<map[i][j];
         }
         cout<<endl;
       }
     }
     if(num==1)
     {
       cout<<m<<" "<<n<<endl;
      for(int i = 1;i<=m;i++)
      {
        for(int j = n;j>=1;j--)
        {
          cout<<lala(map[j][i]);
        }
        cout<<endl;
      }
     }
     if(num == 3)
     {
       cout<<m<<" "<<n<<endl;
       for(int i = m;i>=1;i++)
       {
         for(int j = 1;j<=n;j++)
         {
           cout<<lala(map[j][i]);
         }
         cout<<endl;
       }
     }
     cout<<endl;
   }
  return 0;
}
