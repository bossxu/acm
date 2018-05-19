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
ll gcd(ll a,ll b)
{
  return b==0?a:gcd(b,a%b);
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   std::ios::sync_with_stdio(false);
   int n;
   cin>>n;
   while(n--)
   {
     ll a,b,c;
     cin>>a>>b>>c;
     if(a == 0)
     {
       cout<<"Finite"<<endl;
     }
     else
     {
        ll o = gcd(a,b);
        a/=o;b/=o;
        ll k = gcd(b,c);
        if(b == 1)
        {
          cout<<"Finite"<<endl;
          continue;
        }
        int item = 0;
        while(true)
        {
         k = gcd(b,k);
         if(k == 1) {item = 1;break;}
         b/=k;
         if(b == 1) break;
        }
        if(item) cout<<"Infinite"<<endl;
        else cout<<"Finite"<<endl;
        }

   }
  return 0;
}
