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
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   while(t--)
   {
     int n,b;
     cin>>n>>b;
     int flag = 0;
     int a;
     for(int i = 1;i<=n;i++)
     {
       cin>>a;
       if((a+b)%7 == 0) flag = 1;
     }
     if(flag )
     {
       cout<<"Yes"<<endl;
     }
     else
     cout<<"No"<<endl;
   }
  return 0;
}
