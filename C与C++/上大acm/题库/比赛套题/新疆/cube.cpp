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
const double eps = 1e-5;
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   while(t--)
   {
     ll c ;
     int item = 0;
     cin>>c;
     for(int i = (int)sqrt((c-1)/3);i*i+i<=(c-1)/3;i++)
     {
       if((c-1)%3!=0) break;
       if(i*i+i == (c-1)/3)
       item =1;
     }
     if(item )
     printf("YES\n");
     else
     printf("NO\n");
   }
  return 0;
}
