#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll long long
const int maxn = 1e9+7;
#define clr(a,x) memset(a,x,sizeof(a))
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int t,n,m;
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    int num = 0;
    while( n>0 && m>0)
    {
      if(n == 1 && m == 1)
      {
        break;
      }
      num++;
      if(n>m)
      {
        n-=2;m+=1;
      }
      else
      {
        m-=2;n+=1;
      }
    }
    cout<<num<<endl;
  }
  return 0;
}
