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
#define ll unsigned long long
#define clr(a,x) memset(a,x,sizeof(a))
int main()
{
  ll n;
  int k;
  while(cin>>n>>k)
  {
    for(int i = 1;i<=k;i++)
    {
      if(n%10 == 0)
      {
        n/=10;
      }
      else
      n-=1;
    }
    cout<<n<<endl;
  }
  return 0;
}
