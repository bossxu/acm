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
int map[20][20];
int dp[1<<16];
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int t,co = 0;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
     for(int j = 0;j<n;j++)
      cin>>map[i][j];
    
  }
  return 0;
}
