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
#define pi acos(-1)
#define loge exp(1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     int a,b,n,m;
     cin>>n>>m>>a>>b;
       int k;
       int num = 0;
       for(int i = 1;i<=n*m;i++)
       {
         cin>>k;
         if(k>b || k<a)
         {
           num++;
         }
       }
       if(a>b)
       {
         cout<<"No Solution"<<endl;
         continue;
       }
       cout<<num<<endl;
     }
  return 0;
}
