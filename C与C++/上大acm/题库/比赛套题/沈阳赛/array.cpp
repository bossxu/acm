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
int dp[100005],a[100005];
int n;
template<class Cmp>
int LIS (Cmp cmp)
{
    static int m, end[100005];
    m = 0;
    for (int i=1;i<=n;i++)
    {
        int pos = lower_bound(end, end+m, a[i], cmp)-end;
        end[pos] = a[i], m += pos==m;
    }
    return m;
}
bool greater1(int value)
{
    return value >=1;
}
int main()
{
  //freopen("/home/langman/桌面/in.txt","r",stdin);
  //freopen("/home/langman/桌面/out.txt","w",stdout);
   int t;
   cin>>t;
   while(t--)
   {
     int k;
     cin>>n>>k;
     for(int i=1;i<=n;i++)
     {
       scanf("%d",&a[i]);
     }
    int ans =max(LIS(less_equal<int>()), LIS(greater_equal<int>()) );
    //cout << LIS(less_equal<int>()) << endl;
    //cout << LIS(greater_equal<int>()) << endl;
    if(n-ans<=k)
    printf("A is a magic array.\n");
    else
    printf("A is not a magic array.\n");

   }
  return 0;
}
