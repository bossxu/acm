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
#define mod 2012
#define pi acos(-1)
#define loge exp(1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;

char s[100005];
int main()
{
   int n;
   while(cin>>n)
   {
     set<ll> q;
     ll sum = 0;
     for(int i = 1;i<=n;i++)
     {
       scanf("%s",s);
       for(int i =0;i<strlen(s);i++)
       {
         sum = 0;
         sum+=s[i]-'0';
         q.insert(sum);
         for(int j = i+1;j<strlen(s);j++)
         {
           sum = sum*10 + s[j]-'0';
            q.insert(sum);
         }
       }
     }
     sum = 0;
     for(set<ll>::iterator i = q.begin();i!=q.end();i++)
     {
       sum = (sum + *i)%mod;
     }
     cout<<sum<<endl;
   }
  return 0;
}
