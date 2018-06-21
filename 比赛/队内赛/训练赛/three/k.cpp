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
int shu[3];
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
   int n;
   while(cin>>n)
   {
     if(!n) break;
     clr(shu,0);
     for(int i = 1;i<=n;i++)
     {
       double a;
       cin>>a;
       if(a>0) shu[2]++;
       if(a == 0) shu[1]++;
       if(a<0) shu[0]++;
     }
     cout<<shu[0]<<" "<<shu[1]<<" "<<shu[2]<<endl;
   }
  return 0;
}
