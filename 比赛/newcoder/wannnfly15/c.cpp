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
typedef unsigned long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
   ll n;
   int q;
   while(cin>>n>>q)
   {
     ll a;
     for(int i = 1;i<=q;i++)
     {
        cin>>a;
        ll ans = 0;
        ll k = n;
        //cout<<a<<endl;
        int flag = 0;
        while((a+flag)%2 == 0 && a!=0)
        {
          ll o = k/2;
          flag = k%2;
          if(flag) o++;
          ans+=o;
          k-=o;
          a/=2;
        }
        //cout<<a<<"  "<<flag<<endl;
        if(flag)
        ans+=a/2;
        else
        ans+=a/2+1;
        cout<<ans<<endl;
     }
   }
  return 0;
}
