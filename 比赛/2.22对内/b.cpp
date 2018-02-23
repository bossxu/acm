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
   int shu[1005];
   while(t--)
   {
     int n;
     cin>>n;
     for(int i = 0;i<n;i++){
       cin>>shu[i];
     }
     sort(shu,shu+n);
     for(int i =0;i<n-1;i++)
     {
       cout<<shu[i]<<' ';
     }
     cout<<shu[n-1]<<endl;
   }
  return 0;
}
