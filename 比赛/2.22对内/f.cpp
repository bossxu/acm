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
   int t;
   cin>>t;
   while(t--)
   {
     char s[6];
     int n;
     cin>>n;
     int flag = 0;
     for(int i =1;i<=n;i++)
     {
       cin>>s;
       int a,b,c;
       a = s[0]-'0',b = s[2]-'0',c=s[4]-'0';
       if(s[1] == '+')
       {
         if(a+b==c)
         flag ++;
       }
       else
       {
         if(a-b==c)
         {
           flag++;
         }
       }
     }
     cout<<flag<<"/"<<n<<endl;
   }
  return 0;
}
