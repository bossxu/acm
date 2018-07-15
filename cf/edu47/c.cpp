#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll long long
const int maxn = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
int shu[1005],dp[1005];
#define ld double
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
 int n,m;
 while(cin>>n>>m)
 {
     ll ans=0;
     for(int i=1;i<=m;i++)
     {
         ll x,d;
         cin>>x>>d;
         if(d>=0)
         {
             ans+=n*x+d*(n-1)*n/2;
         }
         else{
           if(n%2){
             int t=(n+1)/2;
             ans+=n*x+2*d*t*(t-1)/2;
           }
           else{
               int t=n/2;
               ans+=n*x+2*d*t*(t-1)/2+(n-t)*d;
           }
         }
     }
     double daan=(double)ans/(1.0*n);
     printf("%.7lf\n",daan);
     //cout<<daan<<endl;
 }
  return 0;
}
