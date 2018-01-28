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
const double eps = 1e-4;
const double in = 3.14159;
int main()
{
    int t;
    cin>>t;
    int co=0;
    while(t--)
    {
      float a,b;
      cin>>a>>b;
      float l=0,r=a/2;
      while(r-l>eps)
      {
        float mid = (l+r)/2;
        if(2*mid > (a-mid)*sin(2*in/b)/sin((in-2*in/b)/2))
        r=mid;
        else
        l=mid;
        //cout<<l<<"---"<<r<<"----"<<sin((2*in-2*in/b)/2)<<endl;
      }
      printf("Scenario #%d:\n%.3f\n\n",++co,l);
    }
  return 0;
}
