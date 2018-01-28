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
#include<map>
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
const double eps = 1e-6;
 ll a[1005];
 int n;
bool check()
{
    for(int i=0;i<n;i++)
       {
           for(int j=i+1;j<n;j++)
           {
               int l=j+1,r=n-1;
               while(l<r)
               {
                int temp =a[i]+a[j]+a[l]+a[r];
                if(temp==0)
                return true;
                if(temp<0)
                l++;
                else 
                r--;
               }
           }
       }
   return false;
}
int main()
{
    while(scanf("%d",&n)==1)       
    { 
       for(int i=0;i<n;i++)
       {
           scanf("%lld",&a[i]);
       }
       sort(a,a+n);
      if(check())
      {
          printf("Yes\n");
      }
      else
      {
          printf("No\n");
      }
    }
    return 0;
}