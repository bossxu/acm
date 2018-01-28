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
ll gcd(ll a,ll b)
{
   return a%b==0?b:gcd(b,a%b);
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   ll a,b;
   while(cin>>a>>b)
   {
    ll z = gcd(a-1,b-1);
    ll s = (a-1)*(b-1)/z;
    a = (a-1)/z,b = (b-1)/z;
    cout<<s-(a-1)*(b-1)+1<<endl;
   }
  return 0;
}
