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
int dp[105][105];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int t ;
   cin>>t;
   while(t--)
   {
     clr(dp,0);
     int n,w,m;
     cin>>n>>w>>m;
     int sumw = 0,summ =0;
     for(int i = 1;i<=n;i++)
     {
       int a;
       cin>>a;
       sumw+=a;
     }
     for(int i = 1;i<=n;i++)
     {
       int a;
       cin>>a;
       summ+=a;
     }
     if(sumw<=w && summ<=m)
     cout<<"YES"<<endl;
     else
     cout<<"NO"<<endl;
   }
  return 0;
}
