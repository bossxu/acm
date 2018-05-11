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
int su[100],item;
ll dfs(ll i,int z,int flag ,int length)
{
  if(flag == length) return i;
  if(item - z +1 < length-flag ) return 0;
  return dfs(i*su[z],z+1,flag+1,length)+dfs(i,z+1,flag,length);
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   ll n;
   while(t--)
   {
     clr(su,0);
     item = 0;
     cin>>n;
     ll ans = n;
     for(int i = 2;i<=sqrt(n);i++)
     {
       if(ans%i == 0) item++;
       while(ans%i == 0)
       {
         su[item]++;
         ans/=i;
       }
     }
     if(ans!=1) su[++item] = 1;
     ll ko = 0;
     for(int i = 1;i<=item;i++)
     {
       int c = dfs(1,1,0,i);
       //cout<<c<<endl;
       ko += i*c;
     }
     cout<<ko<<endl;
   }
  return 0;
}
