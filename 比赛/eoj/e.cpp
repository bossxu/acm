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
   double a,b,c;
   while(cin>>a>>b>>c)
   {
     double d = (a+2*b-c)/2;
     if(d<=0 || a-d<=0 || b-d<=0 ) cout<<"Wrong"<<endl;
     else
     printf("%.2lf\n",d);
   }
  return 0;
}
