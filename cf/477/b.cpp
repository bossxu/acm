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
ll s[100005];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   ll n,a,b;
   while(cin>>n>>a>>b)
   {
     //cout<<n<<endl;
     ll sum = 0;
     for(int i = 1;i<=n;i++)
     {
       cin>>s[i];
       sum+=s[i];
     }
     sort(s+2,s+n+1);
     int flag = 0;
     int item = n;
     while(true)
     {
       if(s[1]*a/sum >= b)
       {
         break;
       }
       sum-=s[item];
       item--;
       flag++;
     }
     cout<<flag<<endl;
   }
  return 0;
}
