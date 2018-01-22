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
int main()
{
   int n,m;
   while(cin>>n>>m)
   {
     if(!n && !m)
     break;
     ll sum = 1;
     for(int i = n;i>n-m;i--)
     {
       sum = sum*i;
     }
     cout<<sum<<endl;
   }
  return 0;
}
