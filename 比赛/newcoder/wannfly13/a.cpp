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
const int mod = 1e9+7;
#define pi acos(-1)
#define loge exp(1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
char s[100005];
int main()
{
   while(gets(s)!=NULL)
   {
     ll num = 1;
     for(int i = 0;i<strlen(s);i++)
     {
       char a = s[i];
       if(a>='0' && a<='9')
       {
         if(a == '0')
         num = num*3%mod;
       }
       if(a>='A'&&a<='Z')
       {
         if(a == 'L' || a == 'I')
         num=num*4%mod;
         else if(a=='O')
         num=3*num%mod;
         else
         num=2*num%mod;
       }
       if(a>='a'&&a<='z')
       {
         if(a == 'l' || a == 'i')
         num=4*num%mod;
         else if(a=='o')
         num=3*num%mod;
         else
         num=2*num%mod;
       }

     }
     cout<<num<<endl;
   }
  return 0;
}
