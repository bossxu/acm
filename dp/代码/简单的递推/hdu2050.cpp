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
#define cle(a,n) for(int i=1;i<=n;i++) a.clear()
const double eps = 1e-6;
int main()
{
  //freopen("/home/langman/桌面/in.txt","r",stdin);
  //freopen("/home/langman/桌面/out.txt","w",stdout);
  int n;
  int t;
  cin>>t;
  while (t--)
  {
    cin>>n;
    cout<<2*n*n-n+1<<endl;
  }
  return 0;
}
