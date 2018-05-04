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
int shu[105];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int n,s;
   while(cin>>n>>s)
   {
     int a,b;
     //cout<<s<<endl;
     for(int i = 1;i<=n;i++)
     {
       cin>>a>>b;
       shu[i]=a*60+b;
     }
     int end;
     int flag = 0;
     if(shu[1] - 0 >=s+1)
     {
       cout<<"0 0"<<endl;
       continue;
     }
     for(int i = 2;i<=n;i++)
     {
       if(shu[i] - shu[i-1]>=2*s+2)
       {
         flag = 1;
         end = shu[i-1]+s+1;
         break;
       }
     }
     if(!flag) {end = shu[n]+s+1;}
     cout<<end/60<<" "<<end%60<<endl;

   }
  return 0;
}
